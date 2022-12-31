#include "../linear_algebra.h"

void test_matprint(){
    printf("~~~ matprint() ~~~\n");
    // Test 1 (2x2)
    #define test_num_row 2
    #define test_num_col 2
    #define test_arrlen test_num_row*test_num_col

    double test_matrix[test_arrlen] = {1.0,2.0,
                                       3.0,4.0};
    matprint(test_num_row,test_num_col,test_matrix);

    // Test 2 (1x4)
    // {1.0,2.0,3.0,4.0};
    matprint(1,4,test_matrix);

    //Test 3 (4x1)
    //{1.0,
    // 2.0,
    // 3.0,
    // 4.0};    
    matprint(4,1,test_matrix);
}

void test_matzero(){
    printf("~~~ matzero() ~~~\n");
    // Test 1 (2x2)
    #define test_num_row 2
    #define test_num_col 2
    #define test_arrlen test_num_row*test_num_col

    double test_matrix[test_arrlen] = {1.0,2.0,
                                       3.0,4.0};
    matzero(test_num_row,test_num_col,test_matrix);
    matprint(test_num_row,test_num_col,test_matrix);
}

void test_mateye(){
    printf("~~~ mateye() ~~~\n");
    // Test 1 (2x2)
    #define test_num_row 2
    #define test_num_col 2
    #define test_arrlen test_num_row*test_num_col

    double test_matrix[test_arrlen] = {1.0,2.0,
                                       3.0,4.0};
    mateye(test_num_row,test_matrix);
    matprint(test_num_row,test_num_col,test_matrix);
}

void test_mattranspose(){
    printf("~~~ mattranspose() ~~~\n");
    #define test_num_row 2
    #define test_num_col 2
    #define test_arrlen test_num_row*test_num_col
    double test_matrix[test_arrlen] = {1.0,2.0,
                                       3.0,4.0};
    double test_result[test_arrlen];
    mattranspose(test_num_row,test_num_col,test_matrix,test_result);
    matprint(test_num_row,test_num_col,test_result);
}

void test_matadd(){
    printf("~~~ matadd() ~~~\n");
    #define test1_num_row 2
    #define test1_num_col 2
    #define test1_arrlen test1_num_row*test1_num_col
    #define test2_num_row 2
    #define test2_num_col 2
    #define test2_arrlen test2_num_row*test2_num_col
    double test1_matrix[test1_arrlen] = {1.0,2.0,
                                         3.0,4.0};
    double test2_matrix[test2_arrlen] = {1.0,2.0,
                                         3.0,4.0};
    double  test_result[test1_arrlen];
    matprint(test1_num_row,test1_num_col,test1_matrix);
    printf("        +\n");
    matprint(test2_num_row,test2_num_col,test2_matrix);
    printf("=\n");
    mattadd(test1_num_row,test1_num_col,test1_matrix,test2_matrix,test_result);
    matprint(test1_num_row,test_num_col,test_result);
}

void test_matmul(){
    printf("~~~ matmul() ~~~\n");
    #define test1_num_row 2
    #define test1_num_col 2
    #define test1_arrlen test1_num_row*test1_num_col
    #define test2_num_row 2
    #define test2_num_col 2
    #define test2_arrlen test2_num_row*test2_num_col
    double test1_matrix[test1_arrlen] = {1.0,2.0,
                                         3.0,4.0};
    double test2_matrix[test2_arrlen] = {1.0,2.0,
                                         3.0,4.0};
    double  test_result[test1_arrlen];
    matprint(test1_num_row,test1_num_col,test1_matrix);
    printf("        *\n");
    matprint(test2_num_row,test2_num_col,test2_matrix);
    printf("=\n");
    matmul(test1_num_row,test1_num_col,test1_matrix,
           test2_num_row,test2_num_col,test2_matrix,
           test_result);
    matprint(test1_num_row,test1_num_col,test_result);
}

void test_error_matmul(){
    printf("~~~ ERROR: matmul() ~~~\n");
    #define error_row 4
    #define error_col 1
    #define error_len error_row*error_col
    #define test2_num_row 2
    #define test2_num_col 2
    #define test2_arrlen test2_num_row*test2_num_col
    double test1_matrix[error_len] = {1.0,2.0,
                                         3.0,4.0};
    double test2_matrix[test2_arrlen] = {1.0,2.0,
                                         3.0,4.0};
    double  test_result[error_len];
    matprint(error_row,error_col,test1_matrix);
    printf("        *\n");
    matprint(test2_num_row,test2_num_col,test2_matrix);
    printf("=\n");
    matmul(error_row,error_col,test1_matrix,
           test2_num_row,test2_num_col,test2_matrix,
           test_result);
    matprint(error_row,error_col,test_result);
}

int main(){
    test_error_matmul();
}
