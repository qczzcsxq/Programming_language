#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
//自定义日志函数 
//日志级别 格式化字符串 自动添加时间戳
typedef enum {
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
}Log_Level;

const char* get_current_time();
void log_message(Log_Level level, const char* format, ...);

int main() {
    
    log_message(LOG_INFO, "This is an information message with a number : %d", 42);
    log_message(LOG_WARNING, "This is an warning message for users: %s", "xi");
    log_message(LOG_ERROR, "This is an error message related to file : %s", "example.txt");
    
    return 0;
}
const char* get_current_time() {
    static char buffer[20]; // static 防止悬挂指针
    time_t now = time(NULL);
    struct tm tm_info;
#ifdef _WIN32   //多系统
    localtime_s(&tm_info, &now);
#else
    localtime_r(&now, &tm_info);
#endif
    strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", &tm_info);
    return buffer;
}
void log_message(Log_Level level, const char* format, ...) {
    const char* level_str;
    
    switch (level) {
    case LOG_INFO:level_str = "INFO"; break;
    case LOG_WARNING:level_str = "WARNING"; break;
    case LOG_ERROR:level_str = "ERROR"; break;
    default:level_str = "UNKNOWN"; break;
    }
    
    printf("[%s] [%s] ", get_current_time(), level_str);
    
    va_list args;
    va_start(args, format);  //format 格式化 
    vprintf(format, args); //格式化输出 有安全形式,不同系统不一样  只打印一句,后面再加"dadw"也不会打印出来,因为你相当于加了未知的无效的参数.如果有多个参数,想把参数单独都取出来,va_arg前先va_end再va_start，清理旧的参数列表
    va_end(args);
    printf("\n");
}
