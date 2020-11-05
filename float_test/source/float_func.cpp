#include "../header/float_funcs.h"

void float_basic_pass(float float_passed) {
    printf("float_basic_pass Started\n");
    
    printf("float_basic_pass Finished\n");
    return;
}

float float_pass_and_return(float float_passed) {
    printf("float_pass_and_return Started\n");
    
    printf("float_pass_and_return Finished\n");
    return(float_passed);
}

float float_maths(float flt1, float flt2){
    printf("float_maths started\n");
    float ans;
    ans = flt1 + flt2;
    printf("Addition complete\n");
    ans = flt1 - flt2;
    printf("Subtraction complete\n");
    ans = flt1 * flt2;
    printf("Multiplication complete\n");
    ans =flt1 / flt2;
    printf("Division complete\n");
    
    printf("float_maths Complete\n");
    return(ans);
}


void double_basic_pass(double double_passed) {
    printf("double_basic_pass Started\n");
    
    printf("double_basic_pass Finished\n");
    return;
}

double double_pass_and_return(double double_passed) {
    printf("double_pass_and_return Started\n");
    
    printf("double_pass_and_return Finished\n");
    return(double_passed);
}

double double_maths(double flt1, double flt2){
    printf("double_maths started\n");
    double ans;
    ans = flt1 + flt2;
    printf("Addition complete\n");
    ans = flt1 - flt2;
    printf("Subtraction complete\n");
    ans = flt1 * flt2;
    printf("Multiplication complete\n");
    ans =flt1 / flt2;
    printf("Division complete\n");
    
    printf("double_maths Complete\n");
    return(ans);
}

