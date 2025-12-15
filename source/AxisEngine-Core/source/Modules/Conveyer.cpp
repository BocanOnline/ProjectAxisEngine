//
// ProjectAxisEngine
// Conveyer.cpp
//

#include <iostream>
#include <memory>

#include "../Kernel.hpp"
#include "../Module.hpp"
#include "Conveyer.hpp"


Core::Conveyer::Conveyer() {

    std::cout << "[Conveyer.cpp] Conveyer created..." << std::endl;
}

Core::Conveyer::~Conveyer() {

    std::cout << "[Conveyer.cpp] Conveyer destroyed..." << std::endl;
}
    
void Core::Conveyer::OnModuleLoaded() {

    this->RegisterForEvent(Core::Event::ON_IDLE);

    std::cout << "[Conveyer.cpp] Conveyer registered for ON_IDLE..." << std::endl;
}

void Core::Conveyer::OnIdle(std::shared_ptr<void> argument) {

    std::cout << "[Conveyer.cpp] Conveyer called by ON_IDLE..." << std::endl; 
}

void Core::Conveyer::OnHalt(std::shared_ptr<void> argument) {

    std::cout << "[Conveyer.cpp] Conveyer called by ON_HALT..." << std::endl; 
}
