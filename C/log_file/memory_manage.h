#pragma once
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include  <assert.h>
/*
安全地分配内存
如果内存分配失败 将记录错误日志并且返回NULL

@param size需要分配内存大小 使用size_t保证跨平台兼容性
@return 指向分配内存的指针 如果分配失败则为NULL
*/

void* safe_malloc(size_t size);

/*
安全地重新分配内存
@param ptr原内存指针
@param newSize 新的内存大小
@return 指向重新分配内存指针 如果重新分配失败则NULL
*/
void* safe_remalloc(void* ptr, size_t newSize);

/*
安全地释放内存
避免释放后使用野指针
*/

void safe_free(void** ptr);
