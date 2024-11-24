

#include <stdio.h>
/*******************************************
重要说明
缺省号代表一个可以变化的参数表。使用保留名 __VA_ARGS__ 把参数传递给宏。
可变参数宏不被ANSI/ISO C++ 所正式支持。因此，你应当检查你的编译器，看它是否支持这项技术。
用GCC和C99的可变参数宏， 更方便地打印调试信息
*******************************************/
#include <stdarg.h>


//#define _LOG_INFO_LEVEL_
//#define _LOG_DEBUG_LEVEL_
//#define _LOG_ERR_LEVEL_
//#define _LOG_FATAL_LEVEL_

#ifdef _LOG_DEBUG_LEVEL_
#define LOG_DEBUG(fmt, ...)             \
        printf("[DEBUG]:[%s-line:%d]: "fmt, __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define LOG_DEBUG(fmt, ...)
#endif

#ifdef _LOG_INFO_LEVEL_
#define LOG_INFO(fmt, ...)              \
        printf("[INFO]:[%s-line:%d]: "fmt, __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define LOG_INFO(fmt, ...)
#endif

#ifdef _LOG_ERR_LEVEL_
#define LOG_ERR(fmt, ...)               \
        printf("[ERR]:[%s-line:%d]: "fmt, __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define LOG_ERR(fmt, ...)
#endif

#ifdef _LOG_FATAL_LEVEL_
#define LOG_FATAL(fmt, ...)             \
        printf("[FATAL]:[%s-line:%d]: "fmt, __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define LOG_FATAL(fmt, ...)
#endif

