#include <stdlib.h>
#include <string.h>

typedef struct vector {
	int* arr;
	int size;
} vector;

/* Initiates a vector pointer. 
 * A vector object must be a pointer to use the freeVector and initVector methods. Otherwise, 
 * user must allocate memory by themselves for the vector. Vectors instantiated without using 
 * this method and without being pointers are not supported by the following vector methods. 
 * Use pointers.
 *
 * Initializes the vector's array to NULL and the size to 0. 
 * Allocates memory using malloc, and as such, memory that has been instantiated without being 
 * filled should not be relied on to hold any certain value, such as 0, unless memset has been 
 * explicitly called.
 *
 * Usage:
 * 	vector *my_vector = initVector();
 */
vector* initVector()
{
	vector *v = (vector*)malloc(sizeof(int*) + sizeof(int));
	v->arr = NULL;
	v->size = 0;
	return v;
}

/* Frees any vector instantiated using the initVector() method.
 * Frees both vector array and the struct itself.
 * Do not call if vector was not instantiated with initVector because the behavior
 * will be undefined.
 */
void freeVector(vector *v)
{
	free(v->arr);
	free(v);
}

/* Adds an integer to the last position of the vector, adding a position there for said integer.
 * Increases the size value of the vector as well.
 */
void pushBackVector(vector *v, int value)
{
	int* temp = (int*)malloc(sizeof(int)*v->size);
	memcpy(temp, v->arr, sizeof(int)*v->size);
	free(v->arr);
	v->size++;
	v->arr = (int*)malloc(sizeof(int)*v->size);
	memcpy(v->arr, temp, sizeof(int)*(v->size - 1));
	v->arr[v->size - 1] = value;
	free(temp);
}

/* Inserts an integer to the specified index, shifting all values after it back one space. Increases
 * the size of the vector object. 
 *
 * Example: 
 * Vector1: [1, 2, 3, 4, 5] Before insertion
 * 
 * insertVector(Vector1, 2, 6);
 *
 * Vector1: [1, 2, 6, 3, 4, 5] After insertion
 */
void insertVector(vector *v, int index, int value)
{
	int* temp = (int*)malloc(sizeof(int)*(v->size));
	memcpy(temp, v->arr, sizeof(int)*(v->size));
	free(v->arr);
	v->size++;
	v->arr = (int*)malloc(sizeof(int)*v->size);
	memcpy(v->arr, temp, sizeof(int)*(v->size - 1));
	for(int i = v->size - 1; i > index; i--)
	{
		v->arr[i] = temp[i-1];
	}
	v->arr[index] = value;
	free(temp);
}

/* Sets a specific index in the vector to a specific value
 */
void setVector(vector *v, int index, int value)
{
	if(index < v->size && index >= 0)
		v->arr[index] = value;
}

/* Removes an index from the vector. Shifts all value after it left one space
 * and decreases the size;
 */
void deleteVector(vector *v, int index)
{
	if(index >= v->size || index < 0)
		return;
	int* temp = (int*)malloc(sizeof(int)*v->size);
	memcpy(temp, v->arr, sizeof(int)*v->size);
	free(v->arr);
	v->size--;
	v->arr = (int*)malloc(sizeof(int)*v->size);

	memcpy(v->arr, temp, sizeof(int)*index);
	memcpy(v->arr+index+1, temp, sizeof(int)*(v->size - index));
	//memcpy(v->arr + (v->size - index), temp+index+1, sizeof(int)*(v->size - index + 1));
	free(temp);
}

/* Given an amount of elements to be copied from a source vector to a destination vector,
 * if the amount of elements is larger than what is in the source vector, the amount of
 * elemenents transferred is the size of the source vector. Otherwise, the amount
 * transferred is equal to the given size. The destination vector is always cleared, and 
 * reallocated before being filled, so that the two vectors given are exactly the same, save
 * for their memory address.
 */
void copyVector(vector *src, vector *dst, size_t size)
{
	if(size > 0 && size <= src->size && size)
	{
		free(dst->arr);
		dst->arr = (int*)malloc(sizeof(int)*size);
		dst->size = size;
		memcpy(dst, src, size);
	}
	else if(size > 0 && size > src->size)
	{
		free(dst->arr);
		dst->arr = (int*)malloc(sizeof(int)*src->size);
		dst->size = src->size;
		memcpy(dst, src, src->size);
	}
}
