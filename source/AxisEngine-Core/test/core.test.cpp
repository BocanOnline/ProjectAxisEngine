//
// ProjectModuleSystem
// core.test.cpp
//

#include <iostream>

#include <cassert>

#include "../source/Kernel.hpp"

int main(int argc, char** argv) {
    
    std::cout << "[core.test.cpp] Start of main function..." << std::endl;
    
    THEKERNEL.Run();

    std::cout << "[core.test.cpp] End of main function..." << std::endl;
}
