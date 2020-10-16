#include <stdio.h>

#include "./header/extra_funcs.h"

void same_file_test_func(int num_to_print);
int seperate_file_func(char char_to_print);


int main() {
    int a =3;
    int b = 5;
    int c = a + b;

    printf("%d + %d = %d\n", a, b, c);
    printf("Hello, World!\n");

    printf("\n========================\n");
    printf("Same File Function Test:\n");
    printf("========================\n");

    same_file_test_func(4);

    printf("\n\n=============================\n");
    printf("Different File Function Test:\n");
    printf("=============================\n");

    int ret = seperate_file_func('i');
    
    printf("Num returned from seperate file: %d\n", ret);

    printf("\n\n");
    return(0);
}

void same_file_test_func(int num_to_print) {
    printf("Printing from a seperate function in the same file!\n");
    printf("This is the number that was passed: %d", num_to_print);
}