#pragma once
#include "types.h"
#include <stdarg.h>
#include <stdbool.h>

//日志级别
typedef enum {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_FATAL
}LogLevel;
/*
初始化日志模块
@params logFilePath 指定日志文件的路径 如果为NULL 日志将输出到标准输出
@return 成功就返回true 否则返回false
*/
bool logger_init(const char* logFilePath);

/*
终止日志模块
*/
void logger_close(void);

/*
写日志
@param level 日志级别
@param format 日志信息的格式字符串,printf
@param ... 可变参数列表 提供格式化字符串的数据
*/
void log_message(LogLevel level, const char* format, ...);

/*
设置当前日志级别
@param level 新的日志级别
*/
void set_log_level(LogLevel level);
