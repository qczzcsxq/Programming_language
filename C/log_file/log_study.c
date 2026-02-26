#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <stdbool.h>
#include "types.h"
#include "logger.h"
#include "application_logic.h"
#include "memory_manage.h"
#include "error_handling.h"
#include "pointer_safety.h"


/*
日志错误系统
模块
1.跨平台的基础数据类型
2.日志模块
3.日志级别模块
4.封装内存分配和释放安全操作
5.统一错误处理策略 记录错误，警告，致命错误
6.检查指针
7.包含主要运行逻辑
*/
int main() {
    
   //初始化应用程序
    if (!app_init()) {
        log_message(LOG_ERROR, "Application initialization failed.");
        logger_close();
        return EXIT_FAILURE;
    }
    if (!app_execute()) {
        log_message(LOG_ERROR, "Application execution failed.");
        app_cleanup();
        logger_close();
        return EXIT_FAILURE;
    }

    app_cleanup();
    logger_close();
    return EXIT_SUCCESS;
}

