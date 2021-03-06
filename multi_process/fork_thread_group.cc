/*

当下流行通用的并发模型:

   （1）accept + read/write 
        能对付一般简单的请求响应程序；

   （2）accept + fork          
        一个连接创建一个进程处理，Qcmd客户端就是这种模型；

   （3）accept + thread          (mongodb) 
        一个连接创建一个线程处理，Mongodb是这种模型；

   （4）pre fork 
        这里谈到了apache和fpm的并发模型，其接收连接的方式是：
        lock（）
        accept（）
        unlock（），一个进程同时只能处理一个连接，当所有进程都忙时，连接将会阻塞在内核的完成连接队列中。

   （5）pre thread 
        跟（4）类似，相对于进程来说线程的全局数据可以共享；

   （6）pool（reactor）
        单线程Reactor方案，比较适合IO密集的应用，不适合CPU密集的应用；

   （7）reactor+thread-per-task  
        与（6）相比是一个过渡方案，把计算放到了另一个线程上做，但是有个缺点就是一个请求的多个任务如果被放到了不同的线程中处理，不能保证顺序性；

   （8）reactor + work thread    (mysql服务)
        为了保证顺序性，为每个连接创建一个工作线程，但是并发连接数受限于线程数，mysql是这种模型；

   （9）reactors + thread pool 为了避免
   （7）为每个任务创建一个线程的缺陷而提出，固定大小的线程池，reactor负责IO工作，thread pool只负责计算，合适任务彼此独立且IO压力不大的应用；
   （7）（8）（9）都是reactor负责接收连接和IO。

   （10） reactors in threads    (muduo库, memcache的实现)
   每个线程都是reactor，主线程主要负责accept 连接，然后把连接分配给子reactor子线程，这样可以充分利用CPU同时把IO分配到每个线程防止出现一个reactor的处理能力饱和的问题;
   举例：
   atlas 可以认为是这种模型，但是稍有区别：atlas主线程也可以是工作线程；此模型缺点是主线程CPU可能会很高；

   （11） reactors in processes         (nginx进程)
   nginx的并发模型，工作进程之间相互独立，可以热升级，需要注意的是这种模型不能在处理函数中处理大量计算，更不能阻塞，如果有阻塞，性能将会大大的下降；
   举例：
   nginx的并发模型；

   （12） reactors + pool 把（9）和（10）混合，用多个IO thread来处理IO，又使用线程池来处理计算，既适合突发IO，又适合突发计算的应用。

*/

#include <boost/thread/thread.hpp>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>

#include <gflags/gflags.h>
#include <glog/logging.h>

void thread_proc()
{
    int i = 0;
    while(i<100) {
        LOG(INFO) << " thread_id=" << pthread_self() << " i=" << i;
        i++;
    }
}

int main(int argc, char* argv[])
{
    google::ParseCommandLineFlags(&argc, &argv, true);

    pid_t pid = fork();
    if (pid < 0) {
        //error;
        return 0;
    }

    if (pid>0) { // in father
        int status = 0;
        pid_t p = waitpid(-1, &status, 0);
        assert(pid==p);
        printf("child exit status=%d\n", status);
    } 
    
    // in child  
    google::InitGoogleLogging("deam.log"); 
    //FLAGS_log_dir = "./";
    //FLAGS_stderrthreshold = 0;

    boost::thread_group threads;

    for (int i=0; i<10; ++i) {
        threads.create_thread(&thread_proc);
    }  

    threads.join_all();

    google::FlushLogFiles(0);    
    google::ShutdownGoogleLogging();  
}


