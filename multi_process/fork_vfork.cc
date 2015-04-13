/*
Ϊʲôvfork���ӽ�������return�����������ҵ�������exit()����

����֪ʶ:
    1������˵һ��fork��vfork�Ĳ��
        fork �� ����һ���ӽ��̣����Ѹ����̵��ڴ����� copy ���ӽ����С�(���ڵ�ʵ�֣����ڵ��ں˶���дʱ��ֵ����дʱ����һ���ڴ棬���Ǻ�vforkһ������shareһ���á�)
        vfork�� ����һ���ӽ��̣����͸����̵��ڴ����� share һ���á�
        �������Ĳ���ǣ�һ����copy��һ����share��������fork�����Բο����֮ǰ�ġ�һ��fork�������⡷��
        
        �� man vfork һ�£�����Կ�����vfork�������Ĺ����ģ�
        1����֤�ӽ�����ִ�С�
        2�����ӽ��̵���exit()��exec()�󣬸���������ִ�С�

        ��ô��ΪʲôҪ�ɳ�һ��vfork������⣿ ԭ����man pageҲ���ú�����ˣ�

        ��˼�������ġ��� ���ֻ��fork�����Ǻܶ������forkһ���ӽ��̺��execһ���ⲿ��������fork��Ҫcopy�����̵�������������ͱ�ú������ˣ����������ɻ���
        �أ�ע��������fork�����Ż���������ĺ��棩�����ԣ�BSD����˸����ӽ��̹����� vfork�������ɱ��Ƚϵ͡���ˣ�vfork������Ϊ��exec������

    2��Ϊʲôreturn��ҵ���exit()���᣿
        ����������֪���������ӽ��̵ĵ�����exit()������return���������vfork��return�ˣ���ô�������ζmain()����return�ˣ�ע����Ϊ����ջ���ӽ��̹������������������ջ�͹��ˡ�

        ��������ӽ�����return����ô����������Ĺ��̣�
        1���ӽ��̵�main() ���� return�ˣ����ǳ���ĺ���ջ�����˱仯��
        2����main()����return��ͨ������� exit()�����Ƶĺ������磺_exit()��exitgroup()��     
        3����ʱ���������յ��ӽ���exit()����ʼ��vfork���أ��������꣬���ӵ�ջ�������ӽ��̸�return�ɷϵ��ˣ���������ôִ�У�
          ��ע��ջ�᷵��һ������һ��ջ��ַ������ĳЩ�ں˰汾��ʵ�֣�ֱ�ӱ���ջ���󡱾͸����ˣ�Ȼ��������ĳЩ�ں˰汾��ʵ�֣�
                �����п��ܻ��ٴε���main()�����ǽ�����һ��1��ѭ���Ľ����ֱ��vfork ���÷��� error��

        ���ˣ������ٻص� return �� exit��return���ͷžֲ�����������ջ���ص��ϼ�����ִ�С�exitֱ���˵����̡�
        �������c++ ���֪����return����þֲ������7��������exit���ᡣ��ע��exit����ϵͳ���ã���glibc��ϵͳ���� _exit()��_exitgroup()�ķ�װ��

        �ɼ����ӽ��̵���exit() û���޸ĺ���ջ�����ԣ������̵���˳��ִ�С�

    3������fork���Ż�
        �����ԣ�fork̫�أ���vfork��̫Σ�գ����ԣ������˿�ʼ�Ż�fork���ϵͳ���á��Ż��ļ����õ���������дʱ������COW����

        Ҳ����˵������fork�󲢲������Ͽ����ڴ棬����ֻ��������Ҫ�ı��ʱ�򣬲Ż�Ӹ������п������ӽ����У�����fork������ִ��exec�ĳɱ��ͷǳ�С�ˡ�
        ���ԣ�Linux��Man Page�в�������ʹ��vfork() 
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void) {
    int var;
    var = 88;
    if ((pid = vfork()) < 0) {
        printf("vfork error");
        exit(-1);
    } else if (pid == 0) { /* �ӽ��� vfork child process run first*/
        var++;
        return 0;
    }
    printf("pid=%d, glob=%d, var=%d\n", getpid(), glob, var);
    return 0;
}

