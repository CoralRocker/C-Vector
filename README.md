# C-Vector
A vector system modeled on the C++ vector class, with all of the modifier and accessor methods, except for the two emplace methods and the [] operator.

# Accessor Methods
|Method|Usage|
|:-:|:-|
|direct access|(vector name)->arr[index] where "vector name" is the variable, and index is the index of the element you wish to retrieve|
|int atVector(vector *v, int index)|atVector(vec, index) where vec is your vector, and index is the index of the element you wish to retrieve. Similar to the direct access method of retrieving data, except that it checks for whether the index is in bounds or not. If the index is not in bounds, it returns 0|
|int frontVector(vector *v)|frontVector(vec) where vec is the vector. Returns the first element of the given vector, or 0 if there is no first element.|
|int backVector(vector *v)|backVector(vec) where vec is the vector. Returns the last element of the given vector, or 0 if there is no first element.|
|int* dataVector(vector *v)|dataVector(vec) where vec is the vector. Returns a pointer to the array for the vector.|

# Modifier Methods
|Method|Usage|
|:-:|:-|
|void assignVector(vector *v, int index, int val)|assign(vec, index, yourNum) where vec is the vector, index is the index, and yourNum is the value you wish to assign to the index. Does not modify the size of the given vector.|
|void pushBackVector(vector *v, int val)|pushBackVector(vec, yourNum), where vec is the vector, and yourNum is the value you wish to add to the back of the vector. Inserts the value to the back of the vector, thus increases vector size.|
|void popBackVector(vector *v)|popBackVector(vec) where vec is the vector. Removes the last element from the vector. Decreases size of vector.|
|void insertVector(vector *v, int index, int val)|insertVector(vec, index, yourNum) where vec is the vector, index is the index, and yourNum is the value you wish to insert. Inserts an element at the given position, and shifts all succeeding indexes back by one in order to create space for given element. Increases size of vector.|
|void eraseVector(vector *v, int index)|eraseVector(vec, index) where vec is the vector, and index is the index. Removes the element at the given index. Shifts succeeding elements to the left one, and shortens the vector to fit the number of elements. Decreases the size of the vector.|
|void swapVector(vector *v1, vector *v2)|swapVector(vec1, vec2) where vec1 and vec2 are both vectors. Switches the memory addresses pointed to by the vector variables. Does not change any of the vectors' data.|
|void clearVector(vector *v)|clearVector(vec) where vec is the vector. Sets all elements in the vector to 0, then frees the memory pointing to it. Does not free vector itself, only vector data array. Sets size of vector to 0 and array pointer to NULL.|

# Initializing a Vector
There is a given method `vector* initVector(void)` that creates and returns an empty vector. The method allocates memory for the vector and its data array using malloc. Thus, the `void freeVector(vector *)` method is provided to free memory used by vectors instantiated by the `initVector()` method.

# More Information
The comments above their respective methods are the best source for information about the methods quirks and usage. 
