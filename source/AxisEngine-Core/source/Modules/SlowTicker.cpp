//
// ProjectAxisEngine
// SlowTicker.cpp
//

#include <iostream>
#include <memory>

#include "../Kernel.hpp"
#include "../Module.hpp"
#include "SlowTicker.hpp"


Core::SlowTicker::SlowTicker() {

    std::cout << "[SlowTicker.cpp] SlowTicker created..." << std::endl;
}

Core::SlowTicker::~SlowTicker() {

    std::cout << "[SlowTicker.cpp] SlowTicker destroyed..." << std::endl;
}
    
void Core::SlowTicker::OnModuleLoaded() {

    this->RegisterForEvent(Core::Event::ON_IDLE);

    std::cout << "[SlowTicker.cpp] SlowTicker registered for ON_IDLE..." << std::endl;
}

void Core::SlowTicker::OnIdle(std::shared_ptr<void> argument) {

    std::cout << "[SlowTicker.cpp] SlowTicker called by ON_IDLE" << std::endl; 

    THEKERNEL.CallEvent(Core::Event::ON_SECOND_TICK, nullptr);

}
