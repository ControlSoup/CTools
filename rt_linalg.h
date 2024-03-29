/*
Linear Algebra 0.1 

Version: 0.1

Series of functions to perform linear algebra operations on microcontrollers

by: Joe Wilson
    
Source:
    Dynamic linear algebra library->  https://www.andreinc.net/2021/01/20/writing-your-own-linear-algebra-matrix-library-in-c

*/

/*
================
Macros
================
*/

// Includes
#ifndef _STDIO_H_
#define _STDIO_H_
#include <stdio.h>
#endif

#ifndef _STDLIB_H_
#define _STDLIB_H_
#include <stdlib.h>
#endif

// Readablity Macros
#define rows 0
#define cols 1

// Converts the dimesions of a matrix, to its equivlanet array length
#define dim2arrlen(i,j) (2 + (i * j))

// Converts the row collumn coordinate to a matrix array coordinate
#define rowcol2matrix(i,j,num_col) (2 + (i * num_col + j)) 

// Ensure the result has the correct dimensions in its first two elements
#define adjust_result_dim(i,j,result) do{\
    if (result[rows] != i) result[rows] = i;\
    if (result[cols] != j) result[cols] = j;\
    } while(0)


/*
================
Matrix Operations

Notes:
    All alogirhtms for operations are based on for loops, this could be improved upon
================
*/

void matprint(float matrix[]){
    /*
    Overview: 
        Prints the elements of a matrix to the terminal
    Inputs:
        matrix = Input matrix
    */
    int num_row = matrix[rows];
    int num_col = matrix[cols];

    unsigned int i,j;
    printf("-\n");
    for (i = 0; i < num_row; i++){
        printf("[");
        for (j = 0; j < num_col; j++){
            printf(" %lf ",matrix[rowcol2matrix(i,j,num_col)]);
        }
        printf("]\n");
    }
    printf("-\n");
}

void matzero(unsigned int  num_row, unsigned int num_col, 
             float result[dim2arrlen(num_col,num_col)]){
    /*
    Overview:
        Modifies the contents of result[] with zeros
    Inputs:
        num_row = Number of rows in the input matrix
        num_col = Number of collumns in input the matrix
        result  = Result matrix, that is to be modified
    */

    unsigned int i,j;
    for (i = 0; i < num_row; i++) 
    for (j = 0; j < num_col; j++){
        result[rowcol2matrix(i,j,num_col)] = 0.0;
    }
}

void mateye(unsigned int  num_row_and_num_col, 
            float result[dim2arrlen(num_row_and_num_col,num_row_and_num_col)]){
    /*
    Overview:
        Modifies the contents of result[] with and idenity matrix
    Inputs:
        num_row = Number of rows in the input matrix
        result  = Result matrix, that is to be modified
    */
    unsigned int i,j;
    for (i = 0; i < num_row_and_num_col; i++) 
    for (j = 0; j < num_row_and_num_col; j++){
        if (i == j) result[rowcol2matrix(i,j,num_row_and_num_col)] = 1.0;
        else        result[rowcol2matrix(i,j,num_row_and_num_col)] = 0.0;
    }
    
}

void mattranspose(float matrix[], float result[]){
    /*
    Overview:
        Modifies the contents of result[] with the transpose of matrix[num_row*num_col]
    Inputs:
        matrix = Input matrix
        result = Result matrix, that is to be modified
    */
    unsigned int num_row = matrix[rows], num_col = matrix[cols];
    adjust_result_dim(num_row,num_col,result); 
   
    unsigned int i,j;
    for (i = 0; i < num_row; i++) 
    for (j = 0; j < num_col; j++){
        result[rowcol2matrix(j,i,num_col)] = matrix[rowcol2matrix(i,j,num_col)];
    }
}

void matadd(float m1[], float m2[], float result[]){
    /*
    Overview:
        Modifies the contents of result[] with the matrix addition of m1[] and m2[]
        
    Input:
        m1     = First input matrix
        m2     = Secound input matrix
        result = Result matrix, that is to be modified
    */
    

    unsigned int num_row = m1[rows], num_col = m1[cols];

    if ((num_row != m2[rows]) || (num_col != m2[cols])){
            printf("ERROR : Matrix dimensions are not equal!\n");
            exit(-1);
    } 

    adjust_result_dim(num_row,num_col,result);
    
    unsigned int i,j;
    for (i = 0; i < num_row; i++) 
    for (j = 0; j < num_col; j++){
        result[rowcol2matrix(i,j,num_col)] = m1[rowcol2matrix(i,j,num_col)] + m2[rowcol2matrix(i,j,num_col)];
    }
}

void matadd_const(float matrix[], float constant, float result[]){
    /*
    Overview:
        Modifies the contents of result[] with addition of matrix[] and constant
        
    Input:
        matrix = First input matrix
        m2     = Secound input matrix
        result = Result matrix, that is to be modified
    */
    unsigned int num_row = matrix[rows], num_col = matrix[cols];

    adjust_result_dim(num_row,num_col,result);
    
    unsigned int i,j;
    for (i = 0; i < num_row; i++) 
    for (j = 0; j < num_col; j++){
        result[rowcol2matrix(i,j,num_col)] = matrix[rowcol2matrix(i,j,num_col)] + constant;
    }
}

void matmul(float m1[], float m2[], float result[]){
    /*
    Overview:
        Modifies the contents of result[] with the matrix multiplication of m1[] and m2[]
       
    Input:
        m1     = First input matrix
        m2     = Secound input matrix
        result = Result matrix, that is to be modified
    */
    
    unsigned int m1_num_row = m1[rows], m1_num_col = m1[cols];
    unsigned int m2_num_row = m2[rows], m2_num_col = m2[cols];

    // Check that matrix multiplication is possible
    if (m1_num_row != m2_num_col){
        printf("ERROR : m1_num_row != m2_num_col, matmul is not possible");
        exit(-1);
    }
    adjust_result_dim(m1_num_col,m2_num_col,result);
    
    matzero(m1_num_row,m2_num_col,result); //ensure result is zero

    unsigned int i,j,k;
    for (i = 0; i < m1_num_row; i++) 
    for (j = 0; j < m2_num_col; j++) 
    for (k = 0; k < m1_num_col; k++){
        result[rowcol2matrix(i,j,m2_num_col)] +=  
        m1[rowcol2matrix(i,k,m1_num_col)] * m2[rowcol2matrix(k,j,m2_num_col)];
    }
}

void matmul_const(float matrix[], float constant, float result[]){
    /*
    Overview:
        Modifies the contents of result[] with product of matrix[] andconst
        
    Input:
        matrix = First input matrix
        m2     = Secound input matrix
        result = Result matrix, that is to be modified
    */
    unsigned int num_row = matrix[rows], num_col = matrix[cols];

    adjust_result_dim(num_row,num_col,result);
    
    unsigned int i,j;
    for (i = 0; i < num_row; i++) 
    for (j = 0; j < num_col; j++){
        result[rowcol2matrix(i,j,num_col)] = matrix[rowcol2matrix(i,j,num_col)] * constant;
    }
    
}


