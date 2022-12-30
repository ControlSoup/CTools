#include "../linear_algebra.h"

void test_rowcolumn2array(){
    double* elements = {0,1.0,6.0,0};
    matrix test_matrix = {2,2,elements};
    printf("%d",rowcolumn2array(1,1,2));
}

void test_matget_element(){
    double* elements = {0,1.0,6.0,0};
    matrix test_matrix = {2,2,elements};
    printf("%lf\n",test_matrix.num_col);
    printf("%lf",matget_element(test_matrix,1,1));
}

void test_print_matrix(){
    double* elements = {0,1.0,6.0,0};
    matrix test_matrix = {2,2,elements};
    print_matrix(test_matrix);
}

void test_zero(){
    matrix test_matrix = matzero(2,2);
    print_matrix(test_matrix);
    test_matrix = matzero(3,3);
    print_matrix(test_matrix);
    test_matrix = matzero(5,5);
    print_matrix(test_matrix);
}

int main(){
    test_zero();
}