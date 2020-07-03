#include "pp-utils.h"

void init_dimension_array(dimension_array *arr, size_t initialSize) {
	arr->array = (struct size_item *)malloc(initialSize * sizeof(struct size_item));
	arr->used = 0;
	arr->size = initialSize;
}

void insert_dimension_array(dimension_array *arr, dimension_item element) {
	if (arr->used == arr->size) {
		arr->size *= 2;
		arr->array = (struct size_item *)realloc(arr->array, arr->size * sizeof(struct size_item));
	}
	arr->array[arr->used++] = element;
}

void free_dimension_array(dimension_array *arr) {
	free(arr->array);
	arr->array = NULL;
	arr->used = arr->size = 0;
}

dimension_item get_optimal_dimensions(dimension_array *arr, int threshold) {
	dimension_item dimensions;
	for(i = 0; i < arr.used; i++) {
    		int prev = arr.array[i].seq - arr.array[i-1].seq;
		int next = arr.array[i+1].seq - arr.array[i].seq;
    		if (prev >= threshold && next >= threshold) {
      			if (arr.array[i].width > dimensions.width) {
        			dimensions.width = arr.array[i].width;
			}
			if (arr.array[i].height > dimensions.height) {
        			dimensions.height = arr.array[i].height;
			}
    		}
  	}
	return dimensions;
}
