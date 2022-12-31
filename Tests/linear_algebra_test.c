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
void test_matzeros(){
    printf("~~~ matzeros() ~~~\n");
    // Test 1 (2x2)
    #define test_num_row 2
    #define test_num_col 2
    #define test_arrlen test_num_row*test_num_col

    double test_matrix[test_arrlen] = {1.0,2.0,
                                       3.0,4.0};
    matzeros(test_num_row,test_num_col,test_matrix);
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
    printf("~~~ matttranspose() ~~~\n");
    #define test_num_row 2
    #define test_num_col 2
    #define test_arrlen test_num_row*test_num_col
    double test_matrix[test_arrlen] = {1.0,2.0,3.0,4.0};
    double test_result[test_arrlen];
    mattranspose(test_num_row,test_num_col,test_matrix,test_result);
    matprint(test_num_row,test_num_col,test_result);
}

int main(){
    test_matzeros();
    test_mateye();
}
