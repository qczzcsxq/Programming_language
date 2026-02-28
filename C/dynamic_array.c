#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int* data;  //动态
	int size;
	int capacity;
}Array;

Array* create_array(size_t init_capacity);
bool append_element(Array* arr,int value);
void print_array(Array* arr);

int main() {
	Array* arr1 = create_array(5);
	append_element(arr1, 5);
	append_element(arr1, 4);
	append_element(arr1, 3);
	append_element(arr1, 2);
	append_element(arr1, 1);
	append_element(arr1, 6);
	print_array(arr1);
	return 0;
}
Array* create_array(size_t init_capacity) {
	Array* arr = (Array*)malloc(sizeof(Array));
	if (!arr) {
		fprintf(stderr, "Failed to allocate the struct 'Array'.");
		return NULL;
	}
	arr->data = (int*)malloc(init_capacity * sizeof(int));
	if (!arr->data) {
		fprintf(stderr, "Failed to allocate the array.");
		free(arr);
		return NULL;
	}
	arr->capacity = init_capacity;
	arr->size = 0;
	return arr;

}
bool append_element(Array* arr,int value) {
	if (!arr) return 0;   //！

	if (arr->size >= arr->capacity) {
		size_t new_capacity = arr->capacity * 2;
		int* temp = (Array*)realloc(arr->data, new_capacity * sizeof(int)); // ！ arr->data  not  arr
			if (!temp) {
				return NULL;
		}
			arr->data = temp;
			arr->capacity = new_capacity;
	}
	arr->data[arr->size++] = value;  // ！
	return 1;
}
void print_array(Array* arr) {
	for (size_t i = 0; i < arr->size; ++i) {
		printf("%d ", arr->data[i]);
	}
}
