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

size_item get_optimal_dimensions(size_array *arr, int threshold) {
	size_item _size;
	for(i = 0; i < arr.used; i++) {
    		int prev = arr.array[i].seq - arr.array[i-1].seq;
		int next = arr.array[i+1].seq - arr.array[i].seq;
    		if (prev >= 10 && next >= 10) {
      			if (arr.array[i].width > _size.width) {
        			_size.width = arr.array[i].width;
			}
			if (arr.array[i].height > _size.height) {
        			_size.height = arr.array[i].height;
			}
    		}
  	}
	return _size;
}
