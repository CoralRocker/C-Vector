#include <stdio.h>
#include "Vector.h"

void printVector(vector *v)
{
	for(int i = 0; i < v->size; i++)
	{
		printf("Vector %d: %d\n", i, v->arr[i]);
	}
}	

int main()
{
	vector *v = initVector();
	
	for(int i = 0; i < 20; i++)
		insertVector(v, i, i*3 + 1);
	
	printf("Initial Vector: \n");
	printVector(v);

	printf("\n\nDeleting element %d ...\n", v->size - 1);
	deleteVector(v, v->size-1);

	printVector(v);
	freeVector(v);
}	
