#ifndef  _MACRO_DEFINE
#define  _MACRO_DEFINE

//============basic===================

#define log_public(log_fmt, log_arg...) \
    do{ \
        PUBLIC_W.log(LL_PUBLIC, log_fmt "\n", ##log_arg); \
    } while (0)

#define log_error(log_fmt, log_arg...) \
    do{ \
        WARN_W.log(LL_ERROR,   "[%s:%d][%s] " log_fmt "\n", \
                     __FILE__, __LINE__, __FUNCTION__, ##log_arg); \
    } while (0) 

#define log_warn(log_fmt, log_arg...) \
    do{ \
        WARN_W.log(LL_WARNING,   "[%s:%d][%s] " log_fmt "\n", \
                     __FILE__, __LINE__, __FUNCTION__, ##log_arg); \
    } while (0) 

#define log_notice(log_fmt, log_arg...) \
    do{ \
        INFO_W.log(LL_NOTICE,   "[%s:%d][%s] " log_fmt "\n", \
                     __FILE__, __LINE__, __FUNCTION__, ##log_arg); \
    } while (0) 

#define log_trace(log_fmt, log_arg...) \
    do{ \
        INFO_W.log(LL_TRACE,   "[%s:%d][%s] " log_fmt "\n", \
                     __FILE__, __LINE__, __FUNCTION__, ##log_arg); \
    } while (0) 

#ifdef DEBUG

#define log_debug(log_fmt, log_arg...) \
    do{ \
        INFO_W.log(LL_DEBUG,   "[%s:%d][%s] " log_fmt "\n", \
                     __FILE__, __LINE__, __FUNCTION__, ##log_arg); \
    } while (0) 

#else 

#define log_debug(log_fmt, log_arg...) \
    do{ \
        break; \
    } while (0) 

#endif

//============extend===================
#define MACRO_RET(condition, return_val) {\
    if (condition) {\
        return return_val;\
    }\
}

#define MACRO_WARN(condition, log_fmt, log_arg...) {\
    if (condition) {\
        log_warn( log_fmt, ##log_arg);\
    }\
}

#define MACRO_WARN_RET(condition, return_val, log_fmt, log_arg...) {\
    if ((condition)) {\
        log_warn( log_fmt, ##log_arg);\
		return return_val;\
    }\
}

#define  redis_error  1001
#define  debug_error  1000

#define monitor(tag_id, log_fmt, log_arg...) \
	 do{ \
        log_notice("[%s:%d][%s] STMT=%d||" log_fmt "\n", \
                     __FILE__, __LINE__, __FUNCTION__, tag_id, ##log_arg); \
    } while (0);

#endif
