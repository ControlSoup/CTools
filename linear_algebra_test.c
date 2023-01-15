#include "linear_algebra.h"

void test_matprint(){
    printf("~~~ matprint() ~~~\n");

    float test_matrix[dim2arrlen(3,3)] = {3,3,
                                          1,2,3,
                                          4,5,6,
                                          7,8,9};
    matprint(test_matrix);
}

void test_matzero(){
    printf("~~~ matzero() ~~~\n");

    float test_result_matrix[dim2arrlen(3,3)];
    matzero(3,3,test_result_matrix);
    matprint(test_result_matrix);
}

void test_mateye(){
    printf("~~~ mateye() ~~~\n");

    float test_matrix[dim2arrlen(3,3)]; 
    mateye(3,test_matrix);
    matprint(test_matrix);
}

void test_mattranspose(){
    printf("~~~ mattranspose() ~~~\n");
    
    float test_matrix[dim2arrlen(3,3)] = {3,3,
                                          1,2,3,
                                          4,5,6,
                                          7,8,9};
    float test_result[dim2arrlen(3,3)];
    mattranspose(test_matrix,test_result);
    matprint(test_result);
}

void test_matadd(){
    printf("~~~ matadd() ~~~\n");
    float test_matrix1[dim2arrlen(3,3)] = {3,3,
                                           1,2,3,
                                           4,5,6,
                                           7,8,9};
    float test_matrix2[dim2arrlen(3,3)] = {3,3,
                                           1,2,3,
                                           4,5,6,
                                           7,8,9};
    float test_result[dim2arrlen(3,3)];
    matadd(test_matrix1,test_matrix2,test_result);
    matprint(test_result);
}

void test_matadd_const(){
    printf("~~~ matadd_const() ~~~\n");
    float test_matrix[dim2arrlen(3,3)] = {3,3,
                                           1,2,3,
                                           4,5,6,
                                           7,8,9};
    float test_result[dim2arrlen(3,3)];
    matadd_const(test_matrix,10.0,test_result);
    matprint(test_result);
}

void test_matmul(){
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
}

void test_matmul_const(){
    printf("~~~ matmul_const() ~~~\n");
    float test_matrix[dim2arrlen(3,3)] = {3,3,
                                           1,2,3,
                                           4,5,6,
                                           7,8,9};
    float test_result[dim2arrlen(3,3)];
    matmul_const(test_matrix,10.0
    ,test_result);
    matprint(test_result);
}


// void test_error_matmul(){
// }

// void test_matinv(){
// }

int main(){
    test_matprint();
    test_matzero();
    test_mateye();
    test_mattranspose();
    test_matadd();
    test_matadd_const();
    test_matmul();
    test_matmul_const();
}
