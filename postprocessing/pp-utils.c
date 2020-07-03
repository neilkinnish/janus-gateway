#include "pp-utils.h"

void init_array(size_array *arr, size_t initialSize) {
	arr->array = (struct size_item *)malloc(initialSize * sizeof(struct size_item));
	arr->used = 0;
	arr->size = initialSize;
}

void insert_array(size_array *arr, size_item element) {
	if (arr->used == arr->size) {
		arr->size *= 2;
		arr->array = (struct size_item *)realloc(arr->array, arr->size * sizeof(struct size_item));
	}
	arr->array[arr->used++] = element;
}

void free_array(size_array *arr) {
	free(arr->array);
	arr->array = NULL;
	arr->used = arr->size = 0;
}
