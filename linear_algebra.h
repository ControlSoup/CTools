/*
Linear Algebra 0.1 

Date: 12.29.22

Series of functions to perform lienar algebra operations

copied by : Joe Wilson

Notes:  
    Coded as needed in personal projects
    Generalization is currently not working

Source:
    Based on https://www.andreinc.net/2021/01/20/writing-your-own-linear-algebra-matrix-library-in-c


*/
#include <stdio.h>
#include <stdlib.h>

#define rowcolumn2array(i,j,num_col) i * num_col + j

typedef unsigned int u_int;

/*
================
Matrix Operations
================
*/

typedef struct{
    u_int num_row;
    u_int num_col;
    double* element;
} matrix;

matrix matzero(u_int m, u_int n){
    double* elements;
    u_int i,j;
    for (i  = 1; i <= m; i++){
        for (j = 1; j <= n; j++){
            elements[rowcolumn2array(i,j,n)] = 0.0;
        }
    }
    matrix result = {m,n,elements};
    return result;
}

matrix mateye(u_int c){
    double* elements;
    u_int i,j;
    for (i  = 1; i <= c; i++){
        for (j = 1; j <= c; j++){
            if (i==j){
                elements[rowcolumn2array(i,j,c)] = 1.0;
            }
            else elements[rowcolumn2array(i,j,c)] = 0.0;
        }
    }
    matrix result = {c,c,elements};
    return result;
}

double matget_element(matrix input_matrix, u_int i, u_int j){
    if ((i > input_matrix.num_col) || (j > input_matrix.num_row) || (i < 1) || (j < 1)){
        perror("Coordinate must be inside the matrix\n");
        exit(-1);
    }   
    return input_matrix.element[rowcolumn2array(i,j,input_matrix.num_col)];
}

double* matget_row(matrix input_matrix, u_int j){
    if ((j > input_matrix.num_row ) || (j < 1)){
        perror("Row must exist inside the matrix\n");
        exit(-1);
    }

    double* row;
    u_int i;
    for (i = 1; i <= input_matrix.num_col; i++){
        row[j] = matget_element(input_matrix,i,j);
    }

    return row;
}

double* matget_col(matrix input_matrix, u_int i){
    if ((i > input_matrix.num_row) || (i < 1)){
        printf("Column must exist inside the matrix\n");
        exit(-1);
    }

    double* col;
    u_int j;
    for (j = 1; j <= input_matrix.num_row; j++){
        col[j] = matget_element(input_matrix,i,j);
    }

    return col;
}



matrix matconst(matrix input_matrix, double constant){
    u_int i,j;
    double* elements;
    for (i = 1; i <= input_matrix.num_col; i++){
        for(j = 1; j <= input_matrix.num_row; j++){
            elements[i * input_matrix.num_col + j] *= constant;
        }
    }
    matrix result = {input_matrix.num_row,input_matrix.num_col,elements};
    return result;
}

matrix matadd(matrix matrix_1, matrix matrix_2){
    if ((matrix_1.num_col != matrix_2.num_col) || (matrix_1.num_row != matrix_2.num_row)){
        printf("Both Matrixs need to be the same size\n");
        exit(-1);
    }

    u_int i,j;
    double* elements;
    for (i = 1; i <= matrix_1.num_row; i++){
        for(j = 1; j <= matrix_1.num_col; j++){
            elements[rowcolumn2array(i,j,matrix_1.num_col)] = 
            matget_element(matrix_1,i,j) + matget_element(matrix_2,i,j);
        }
    }
    matrix result = {matrix_1.num_row,matrix_1.num_col,elements};
    return result;
}

matrix matsubtract(matrix matrix_1, matrix matrix_2){
    if ((matrix_1.num_col != matrix_2.num_col) || (matrix_1.num_row != matrix_2.num_row)){
        printf("Both Matrixs need to be the same size\n");
        exit(-1);
    }

    u_int i,j;
    double* elements;
    for (i=1; i <= matrix_1.num_row; i++){
        for(j=1; j <= matrix_1.num_col; j++){
            elements[rowcolumn2array(i,j,matrix_1.num_col)] = matget_element(matrix_1,i,j) - matget_element(matrix_2,i,j);
        }
    }
    matrix result = {matrix_1.num_row,matrix_1.num_col,elements};
    return result;
}


void print_matrix(matrix input_matrix){
    u_int i,j;
    for (i = 1; i <= input_matrix.num_row; i++){
        printf("[");
        for (j = 1; j <= input_matrix.num_col; j++){
            printf(" %lf ",matget_element(input_matrix,i,j));
        }
        printf("]\n");
    }
}