//
// ProjectAxisEngine
// Robot.cpp
//

#include <iostream>
#include <memory>

#include "../Kernel.hpp"
#include "../Module.hpp"
#include "Robot.hpp"


Core::Robot::Robot() {

    std::cout << "[Robot.cpp] Robot created..." << std::endl;
}

Core::Robot::~Robot() {

    std::cout << "[Robot.cpp] Robot destroyed..." << std::endl;
}
    
void Core::Robot::OnModuleLoaded() {

    this->RegisterForEvent(Core::Event::ON_IDLE);
    this->RegisterForEvent(Core::Event::ON_GCODE_RECEIVED);
    this->RegisterForEvent(Core::Event::ON_SECOND_TICK);

    std::cout << "[Robot.cpp] Robot registered for ON_IDLE..." << std::endl;
    std::cout << "[Robot.cpp] Robot registered for ON_GCODE_RECEIVED..." << std::endl;
    std::cout << "[Robot.cpp] Robot registered for ON_SECOND_TICK..." << std::endl;
}

void Core::Robot::OnIdle(std::shared_ptr<void> argument) {

    std::cout << "[Robot.cpp] Robot called by ON_IDLE..." << std::endl;
}

void Core::Robot::OnGcodeReceived(std::shared_ptr<void> argument) {

    std::cout << "[Robot.cpp] Robot called by ON_GCODE_RECEIVED..." << std::endl; 
}

void Core::Robot::OnSecondTick(std::shared_ptr<void> argument) {

    std::cout << "[Robot.cpp] Robot called by ON_SECOND_TICK..." << std::endl;
}
