//
// ProjectAxisEngine
// AxisEngine.hpp
//
#pragma once

#include <iostream>

#include "Kernel.hpp"
#include "Module.hpp"

namespace AxisEngine {

    void Initialize();
    
    void AddModule(std::shared_ptr<Core::Module> module) { // NOLINT
            
        return Core::Kernel::Get().AddModule(module);
    }

    void Run() { // NOLINT

        return Core::Kernel::Get().Run();
    }
}

int main(int argc, char** argv) { // NOLINT

    std::cout << "[AxisEngine.hpp] start of main function..." << std::endl;
    
    AxisEngine::Initialize();

    AxisEngine::Run();
    
    std::cout << "[AxisEngine.hpp] end of main function..." << std::endl;
    return 0;
}

