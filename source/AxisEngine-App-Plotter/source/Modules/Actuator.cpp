//
// ProjectAxisEngine
// Actuator.cpp
//

#include <iostream>
#include <memory>

#include "Kernel.hpp"
#include "Module.hpp"

#include "Actuator.hpp"


Plotter::Actuator::Actuator() {

    std::cout << "[Actuator.cpp] Actuator created..." << std::endl;
}

Plotter::Actuator::~Actuator() {

    std::cout << "[Actuator.cpp] Actuator destroyed..." << std::endl;
}
    
void Plotter::Actuator::OnModuleLoaded() {

    this->RegisterForEvent(Core::Event::ON_GCODE_RECEIVED);

    std::cout << "[Actuator.cpp] Actuator registered for ON_GCODE_RECEIVED..." << std::endl;
}

void Plotter::Actuator::OnGcodeReceived(std::shared_ptr<void> argument) {

    std::cout << "[Actuator.cpp] Actuator called by ON_GCODE_RECEIVED..." << std::endl; 
}
