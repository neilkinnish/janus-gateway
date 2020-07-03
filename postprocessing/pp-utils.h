#include <stdio.h>
#include <stdlib.h>

typedef struct size_item {
	int size;
  int frame;
} size_item;

typedef struct size_array {
	size_item *array;
	size_t used;
	size_t size;
} size_array;

void init_array(size_array *arr, size_t initialSize);
void insert_array(size_array *arr, size_item element);
void free_array(size_array *arr);
