/*! \file    pp-utils.h
 * \author   
 * \copyright GNU General Public License v3
 * \brief    
 * \details  
 * 
 * \ingroup postprocessing
 * \ref postprocessing
 */
#include <stdlib.h>

typedef struct janus_config_container {
	int *array;
	size_t used;
	size_t size;
} ratio_array;
 
void init_array(ratio_array *a, size_t initialSize);
void insert_array(ratio_array *a, int element);
void free_array(ratio_array *a);
void sort_array_asc(int arr[], int n);
int most_frequent_element(int arr[], int n);
