#include "memory_manage.h"
#include "logger.h"

void* safe_malloc(size_t size) {
	assert(size > 0);
	void* ptr = NULL;
	//C11
#if defined(__STDC_VERSION__)&& __STDC_VERSION__ >= 201112L
	ptr = aligned_alloc(alignof(max_align_t), size);
#else
	//c11如果不可用
	ptr = malloc(size);
#endif

	if (ptr == NULL) {
		//在实际应用中 可能不希望在分配失败时停止程序 模拟
		fprintf(stderr, "Memory allocation failed for size %zu.\n", size);
		assert(ptr != NULL);
	}
}

void* safe_remalloc(void* ptr, size_t newSize) {
	void* newPtr = realloc(ptr, newSize);
	if (!newPtr) {
		log_message(LOG_ERROR, "Failed to reallocate  %zu bytes of memory", newSize);
	}
	return newPtr;
}

void safe_free(void** ptr) {
	if (ptr && *ptr) {
		free(*ptr);
		*ptr = NULL;   //防止野指针
	}
	else {
		log_message(LOG_WARNING, "Attempted to free a null or already freed pointer");
	}
}
