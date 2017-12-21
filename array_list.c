#include "array_list.h"
#include <stdlib.h>

struct array_list* al_create(void){

		struct array_list *newList = (struct array_list*)malloc(sizeof(struct array_list*));
		newList->size = 0;
		newList->capacity = INITIAL_SIZE;
		newList->array = (int*)malloc(INITIAL_SIZE * sizeof(int));
		return newList;
}

void al_add(struct array_list* list, int value){

	if(list->size == list->capacity){
		list->capacity *= 3;
		list->capacity /= 2;
		list->array = (int *)realloc(list->array, list->capacity * sizeof(int));
	}
	
	*(list->array + list->size) = value;
	list->size = list->size + 1;
}

int al_get(struct array_list* list, int index){
	return list->array[index];
}

void al_set(struct array_list* list, int index, int value){
	list->array[index] = value;

}
void al_remove(struct array_list* list, int index){
	if(index < list->size){
		for(int i = index; i<list->size; i++){
			if(i == list->size - 1){
				list->array[i] = 0;
			}
			else {
				list->array[i] = list->array[i+1];
			}
		}
	}
	list->size = list->size - 1;
}
int al_size(struct array_list* list){
	return list->size;
}
void al_destroy(struct array_list* list){
	list->size = 0;
	list->capacity = 0;
	free(list->array);
	list->array=NULL;
	free(list);
}
