/*! \file    pp-utils.h
 * \author   
 * \copyright GNU General Public License v3
 * \brief    
 * \details  
 * 
 * \ingroup postprocessing
 * \ref postprocessing
 */
 
static void init_array(Array *a, size_t initialSize) {
	a->array = (int *)malloc(initialSize * sizeof(int));
	a->used = 0;
	a->size = initialSize;
}

static void insert_array(Array *a, int element) {
	if (a->used == a->size) {
		a->size *= 2;
		a->array = (int *)realloc(a->array, a->size * sizeof(int));
	}
	a->array[a->used++] = element;
}

static void free_array(Array *a) {
	free(a->array);
	a->array = NULL;
	a->used = a->size = 0;
}

static void sort_array_asc(int arr[], int n) { 
  	int i = 0, j = 0;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(arr[j] < arr[i]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

static int most_frequent_element(int arr[], int n) { 
	int max_count = 1, res = arr[0], curr_count = 1, i = 0;

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
