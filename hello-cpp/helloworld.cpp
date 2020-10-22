#include <iostream>

#include "extra_funcs.h"

int main(void) {
    std::cout << "Hello World!" << std::endl;

    std::cout << std::endl << "===========================" << std::endl;
    std::cout << "Separate File Function Call" << std::endl;
    std::cout << "===========================" << std::endl << std::endl;

    seperate_file_func('g');

    std::cout << std::endl << "===============================" << std::endl;
    std::cout << "End Separate File Function Call" << std::endl;
    std::cout << "===============================" << std::endl;

    return 0;
}