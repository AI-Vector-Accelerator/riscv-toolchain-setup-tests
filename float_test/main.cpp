#include <stdio.h>

#include "./header/float_funcs.h"

int main(void) {
    printf("Hello, World!\n\n");

    // Basic, in-main stuff
    printf("\n==============================\n");
    printf("Float Variable assignment");
    printf("\n==============================\n");
    float flt = 2.4;
    
    printf("\n==============================\n");
    printf("Float maths");
    printf("\n==============================\n");
    float result = 2.4 + 0.5;

    printf("\n==============================\n");
    printf("Float Printing");
    printf("\n==============================\n");
    printf("Float: %.3f\n\n", result);

    // Float function passes
    printf("\n==============================\n");
    printf("float_basic_pass Starting...\n");
    float_basic_pass(flt);
    printf("float_basic_pass Finished");
    printf("\n==============================\n");

    printf("\n==============================\n");
    printf("float_pass_and_return Starting...\n");
    float float_returned = float_pass_and_return(flt);
    printf("float_pass_and_return Finished");
    printf("\n==============================\n");

    printf("\n==============================\n");
    printf("float_maths Starting...\n");
    float float_returned_maths = float_maths(flt, float_returned);
    printf("float_maths Finished");
    printf("\n==============================\n");

    // Double function passes
    double db1 = 5.3345;
    double db2 = 12.23213;
    printf("\n==============================\n");
    printf("double_basic_pass Starting...\n");
    double_basic_pass(flt);
    printf("double_basic_pass Finished");
    printf("\n==============================\n");

    printf("\n==============================\n");
    printf("double_pass_and_return Starting...\n");
    float double_returned = double_pass_and_return(flt);
    printf("double_pass_and_return Finished");
    printf("\n==============================\n");

    printf("\n==============================\n");
    printf("double_maths Starting...\n");
    float double_returned_maths = double_maths(db1, db2);
    printf("double_maths Finished");
    printf("\n==============================\n");
    




    return 0;
}