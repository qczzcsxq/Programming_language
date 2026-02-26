#pragma once
#include <stdbool.h>

bool is_nullptr(const void* ptr);

/*
安全地解引用指针
如果指针为NULL 记录错误并且返回指定地默认值
@param ptr 待解引用的指针
@param defaultValue 解引用失败时候地默认值
@return 指针指向的值 如果指针为NULl 则为defaultValue.
*/
#define SAFE_DEREF(ptr,defaultValue) \ (is_nullptr(ptr) ? (log_error("Attempted to dereference a NULL pointer."),defaultValue): *(ptr))
// \在宏定义中允许跨越多个行
