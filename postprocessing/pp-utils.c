/*! \file    pp-utils.c
 * \author   
 * \copyright GNU General Public License v3
 * \brief    
 * \details  
 * 
 * \ingroup postprocessing
 * \ref postprocessing
 */

#include "pp-utils.h"
 
void init_array(ratio_array *arr, size_t initialSize) {
	arr->array = (int *)malloc(initialSize * sizeof(int));
	arr->used = 0;
	arr->size = initialSize;
}

void insert_array(ratio_array *arr, int element) {
	if (arr->used == arr->size) {
		arr->size *= 2;
		arr->array = (int *)realloc(arr->array, arr->size * sizeof(int));
	}
	arr->array[arr->used++] = element;
}

void free_array(ratio_array *arr) {
	free(arr->array);
	arr->array = NULL;
	arr->used = arr->size = 0;
}

int most_frequent_element(int arr[], int n) { 
	int max_count = 1, res = arr[0], curr_count = 1, i = 0, j = 0;
	
	// Sort the array ascending
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(arr[j] < arr[i]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	for(i = 1; i < n; i++) { 
		if(arr[i] == arr[i - 1]) { 
			curr_count++; 
		} else { 
			if(curr_count > max_count) { 
				max_count = curr_count; 
				res = arr[i - 1]; 
			} 
			curr_count = 1; 
		} 
	} 

	if(curr_count > max_count) { 
		max_count = curr_count; 
		res = arr[n - 1]; 
	} 

	return res; 
}
