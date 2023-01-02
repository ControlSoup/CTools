/*
Linear Algebra 0.1 

Date: 12.31.22

Series of functions to perform linear algebra operations on microcontrollers

This library might be improved with the proper use of dynamic memory allocation,
in an attempt to avoid possible fragmentation, I have avoided using functions like
malloc()/calloc() to only operate on the stack.

copied by : Joe Wilson

Notes: 
    Coded as needed in personal projects
    
Source:
    Dynamic linear algebra library->  https://www.andreinc.net/2021/01/20/writing-your-own-linear-algebra-matrix-library-in-c


*/
#include <stdio.h>
#include <stdlib.h>

// Conversion from [row][col] to array[x]
#define rowcol2matrix(i,j,num_col) (i * num_col + j) 

typedef unsigned int u_int;

/*
================
Matrix Operations

All alogirhtms for operations are based on for()), this could be massivly improved upon

Notes:
    In this file, a matrix is defined by a double[]
    in order to properly use these functions 
    there are two variables are required:

        - num_row (u_int) = Number of rows in the matrix
        - num_col (u_int) = Number of collumns in the matrix

    Optionally another is often useful:

        - arrlen  (u_int) = num_row * num_col
    
    I keep track of these with the following macro definitions at the top of the file,
    this is my way of sudo intializating the matrix (and allowing for customization later):

        #define matname_num_row i
        #define matname_num_col j
        #define matname_arrlen matname_num_row * matname_num_col

    To initalize the matrix, simply initialze a double[] with the proper size.
    I also format the intialization brackets in the dimensions to help with readability 
    and debugging:

        double matrix[matname_arrlen] = {a11,a12
                                         a21,a22}
    
    To perform an operation, you must populate a result[] matrix with the correct length for the function.
    Then pass both the input matrix and result to the function to modify the result.
    See each function for its requirment. Eg:

        double matrix[matname_arrlen] = {a11,a12
                                         a21,a22}
        double result[matname_arrlen];
        mattranspose(num_row,num_col,matrix,result); // Modifies result[] with the tranpose of matrix
================
*/

void matprint(u_int  num_row, u_int num_col, 
              double matrix[num_row*num_col]){
    /*
    Overview: 
        Prints the elements of a matrix to the terminal
    Inputs:
        num_row (u_int)                   = Number of rows in the input matrix
        num_col (u_int)                   = Number of collumns in input the matrix
        matrix  (double[num_row*num_col]) = Input matrix
    */
    u_int i,j;
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

void matzero(u_int  num_row, u_int num_col, 
             double result[num_row*num_col]){
    /*
    Overview:
        Modifies the contents of result[] with zeros
    Inputs:
        num_row (u_int)                   = Number of rows in the input matrix
        num_col (u_int)                   = Number of collumns in input the matrix
        result  (double[num_row*num_col]) = Result matrix, that is to be modified
    */
    u_int i,j;
    for (i = 0; i < num_row; i++) 
    for (j = 0; j < num_col; j++){
        result[rowcol2matrix(i,j,num_col)] = 0.0;
    }
}

void mateye(u_int  num_row_and_num_col, 
            double result[num_row_and_num_col*num_row_and_num_col]){
    /*
    Overview:
        Modifies the contents of result[] with and idenity matrix
    Inputs:
        num_row (u_int)                   = Number of rows in the input matrix
        num_col (u_int)                   = Number of collumns in input the matrix
        result  (double[num_row*num_col]) = Result matrix, that is to be modified
    */
    u_int i,j;
    for (i = 0; i < num_row_and_num_col; i++) 
    for (j = 0; j < num_row_and_num_col; j++){
        if (i == j) result[rowcol2matrix(i,j,num_row_and_num_col)] = 1.0;
        else        result[rowcol2matrix(i,j,num_row_and_num_col)] = 0.0;
    }
    
}

void mattranspose(u_int  num_row, u_int num_col, 
                  double matrix[num_row*num_col],
                  double result[num_row*num_col]){
    /*
    Overview:
     Modifies the contents of result[] with the transpose of matrix[num_row*num_col]
    Inputs:
     num_row (u_int)                   = Number of rows in the input matrix
     num_col (u_int)                   = Number of collumns in input the matrix
     matrix  (double[num_row*num_col]) = Input matrix
     result  (double[num_row*num_col]) = Result matrix, that is to be modified
    */

    u_int i,j;
    for (i = 0; i < num_row; i++) 
    for (j = 0; j < num_col; j++){
        result[rowcol2matrix(j,i,num_col)] = matrix[rowcol2matrix(i,j,num_col)];
    }
}

void matinv(u_int  num_dim,
            double matrix[num_dim*num_dim],
            double result[num_dim*num_dim]){
    /*
    Overview:
        Modifies the contents of result[] with inverse of the input matrix[]
    
    Input:
        num_rowandcol (u_int)                   = Number of rows in the input matrix
        matrix        (double[num_row*num_row]) = Input matrix
        result        (double[num_row*num_row]) = Result matrix, that is to be modified
    Source:
        https://www.codesansar.com/numerical-methods/matrix-inverse-using-gauss-jordan-method-c-program.htm
    */
    u_int gaus_col = (num_dim+num_dim);
    double gaus_aug[2*num_dim*num_dim];
    double ratio;

    // Augmented matrix with an Identity matrix
    u_int i,j,k;
    for (i = 0; i < num_dim; i++) 
    for (j = 0; j < gaus_col; j++){
        if (j < num_dim) gaus_aug[rowcol2matrix(i,j,gaus_col)] =  matrix[rowcol2matrix(i,j,num_dim)];
        else if (j - num_dim == i) gaus_aug[rowcol2matrix(i,j,gaus_col)] = 1.0;
        else gaus_aug[rowcol2matrix(i,j,gaus_col)] = 0.0;
    }  
    printf(" Augmented matrix: \n ");
    matprint(num_dim,gaus_col,gaus_aug);
    // Gaus elimination
    for (i = 0; i < num_dim; i++){
        if (gaus_aug[rowcol2matrix(i,i,gaus_col)] == 0.0){
            perror(" Guas Jordan Error!");
            printf("matrix[%lf] at coordinates [%d,%d] = %lf\n",rowcol2matrix(i,i,gaus_col),i,i,
                                                                gaus_aug[rowcol2matrix(i,i,gaus_col)]);
            exit(0);
        }
        for (j =0; j < num_dim; j++){
            if (i != j){
                ratio = gaus_aug[rowcol2matrix(j,i,gaus_col)]/gaus_aug[rowcol2matrix(i,i,gaus_col)];
                for (k = 0; k < gaus_col; k ++){
                    gaus_aug[rowcol2matrix(j,k,gaus_col)] -= 
                    ratio/gaus_aug[rowcol2matrix(i,j,gaus_col)];
                }
            } 
        }
    } 

    // Make principal diagnol 
    for(i = 0;i < num_dim; i++)
    for(j = num_dim;j < gaus_col; j++){
        gaus_aug[rowcol2matrix(i,j,gaus_col)] /= 
        gaus_aug[rowcol2matrix(i,i,gaus_col)];
    }
    printf(" Resulting matrix: \n ");
    matprint(num_dim,gaus_col,gaus_aug);
    
}

void mattadd(u_int  num_row, u_int num_col,
             double m1[num_row*num_col],
             double m2[num_row*num_col],
             double result[num_row*num_col]){
    /*
    Overview:
        Modifies the contents of result[] with the matrix addition of m1[] and m2[]
        
    Input:
        num_row    (u_int)                   = Number of rows in the first input matrix
        num_col    (u_int)                   = Number of columns in the first input matrix
        m1         (double[num_row*num_col]) = First input matrix
        m2         (double[num_row*num_col]) = Secound input matrix
        result     (double[num_row*num_col]) = Result matrix, that is to be modified
    */

    u_int i,j;
    for (i = 0; i < num_row; i++) 
    for (j = 0; j < num_col; j++){
        result[rowcol2matrix(i,j,num_col)] = 
        m1[rowcol2matrix(i,j,num_col)] + m2[rowcol2matrix(i,j,num_col)];
    }
}

void matmul(u_int  m1_num_row, u_int m1_num_col,
            double m1[m1_num_row*m1_num_col],
            u_int  m2_num_row, u_int m2_num_col,
            double m2[m2_num_row*m2_num_col],
            double result[m1_num_row*m2_num_col]){
    /*
    Overview:
        Modifies the contents of result[] with the matrix multiplication of m1[] and m2[]
       
    Input:
        m1_num_row (u_int)                         = Number of rows in the first input matrix
        m2_num_col (u_int)                         = Number of columns in the first input matrix
        m1         (double[m1_num_row*m1_num_row]) = First input matrix
        m1_num_row (u_int)                         = Number of rows in the secound input matrix
        m2_num_col (u_int)                         = Number of columns in the secound input matrix
        m2         (double[m2_num_row*m2_num_row]) = Secound input matrix
        result     (double[m1_num_row*m2_num_row]) = Result matrix, that is to be modified
    */
    
    // Check that matrix multiplication is possible
    if (m1_num_col != m2_num_row){
        perror("m1_num_col != m2_num_row, matmul is not possible");
        exit(0);
    }

    matzero(m1_num_row,m2_num_col,result); //ensure result is zero

    u_int i,j,k;
    for (i = 0; i < m1_num_row; i++) 
    for (j = 0; j < m2_num_col; j++) 
    for (k = 0; k < m1_num_col; k++){
        result[rowcol2matrix(i,j,m2_num_col)] +=  
        m1[rowcol2matrix(i,k,m1_num_col)] * m2[rowcol2matrix(k,j,m2_num_col)];
    }
}

