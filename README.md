# CTools
These are a set of C files that I use commonly for C/C++ an Ardunio projects.

## rt_linalg.h 

This is the only file that I currently use, it handles generalized linear algebra 
functions on real time and emebedded systems. 

This file might be improved with the proper use of dynamic memory allocation (mnaybe pooling?).
In an attempt to avoid possible fragmentation, I have avoided using functions like
malloc()/calloc() to only operate on the stack.

A matrix is defined by a float[]. In order to properly use these functions, 
you need to initalize the matrix with its dimentions in the first two elements:

```c
floatn matrix[] = {3,3,
                   a00,a01,a02,
                   a10,a11,a12,
                   a20,a21,a22};
```

I have diverged from the traditional formatting to make visualizing these array matrixs a 
little easier. 

There are a few important macro functions that can be used to make coordinates and 
readability a bit better:

```c
// Readablity Macros
#define rows 0
#define cols 1

// Converts the dimesions of a matrix, to its equivlanet array length
#define dim2arrlen(i,j) (2 + (i * j))

// Converts the row collumn coordinate to a matrix array coordinate
#define rowcol2matrix(i,j,num_col) (2 + (i * num_col + j)) 
```
To perform an operation, you must populate a result[] matrix and ideally using the correct 
length for the function. Then pass both the input matrix and result to the function to modify 
the result. See each function for its requirment.

Matmul Example:

```c
printf("~~~ mamtmul() ~~~\n");
float test_matrix1[dim2arrlen(3,3)] = {3,3,
                                       1,2,3,
                                       4,5,6,
                                       7,8,9};
float test_matrix2[dim2arrlen(3,3)] = {3,3,
                                       1,2,3,
                                       4,5,6,
                                       7,8,9};
float test_result[dim2arrlen(3,3)];
matmul(test_matrix1,test_matrix2,test_result);
matprint(test_result);
```


Outputs:

```
~~~ mamtmul() ~~~
-
[ 30.000000  36.000000  42.000000 ]
[ 66.000000  81.000000  96.000000 ]
[ 102.000000  126.000000  150.000000 ]
-
```

