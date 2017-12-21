#include <stdio.h>
#include <stdlib.h>
#include "array_list.h"

int main(void){


		int size;

		// Creates new ArrayList with a capacity of 10 elements (INITIAL_SIZE)
		struct array_list* testList = al_create();
		// Add 1 to 8 to ArrayList 
		for(int i=1; i<=8; i++){
		al_add(testList,i);
		}
		printf("ArrayList after adding 1 through 8 using al_add method\n");
		// Demonstrates al_size method (returns number of elements in array list)
		size = al_size(testList);
		printf("Size: %d\n",size);
		// Returns values just stored 
		for(int i=0; i<size; i++){
		int x = al_get(testList,i);
		printf("Element at index %d: %d\n",i,x);
		}

		// Uses al_set to change two elements at index 2 and 3 
		al_set(testList,2,20);
		al_set(testList,3,34);

		size = al_size(testList);
		printf("ArrayList after modifying indexes 2 and through using al_set method\n");
		printf("Size: %d\n",size);
		// Returns list with modified values 
		for(int i=0; i<size; i++){
		int x = al_get(testList,i);
		printf("Element at index %d: %d\n",i,x);
		}

		// Demonstrates array resizing itself 
		for(int i = 24; i< 29; i++){
			al_add(testList,i);
		}

		printf("ArrayList resizing itself automatically after adding more values\n");
		size = al_size(testList);
		printf("Size: %d\n",size);
		// Array after being resized / having elements added 
		for(int i=0; i<size; i++){
		int x = al_get(testList,i);
		printf("Element at index %d: %d\n",i,x);
		}

		// Removes value 
		al_remove(testList,7);
		// Size after value being removed 
		size = al_size(testList);
		// Size printed 
		printf("Size: %d\n",size);
		printf("ArrayList after having element at index 7 removed\n");
		// Array after al_remove 
		for(int i=0; i<size; i++){
		int x = al_get(testList,i);
		printf("Element at index %d: %d\n",i,x);
		}

		// deallocates / frees ArrayList and its Array
		al_destroy(testList);


        return 0;
}
