//
// ProjectAxisEngine
// SerialConsole.cpp
//

#include <iostream>
#include <memory>

#include "../Kernel.hpp"
#include "../Module.hpp"
#include "SerialConsole.hpp"


Core::SerialConsole::SerialConsole() {

    std::cout << "[SerialConsole.cpp] SerialConsole created..." << std::endl;
}

Core::SerialConsole::~SerialConsole() {

    std::cout << "[SerialConsole.cpp] SerialConsole destroyed..." << std::endl;
}
    
void Core::SerialConsole::OnModuleLoaded() {

    this->RegisterForEvent(Core::Event::ON_MAIN_LOOP);
    this->RegisterForEvent(Core::Event::ON_IDLE);

    std::cout << "[SerialConsole.cpp] SerialConsole registered for ON_MAIN_LOOP..." << std::endl;
    std::cout << "[SerialConsole.cpp] SerialConsole registered for ON_IDLE..." << std::endl;

}

void Core::SerialConsole::OnMainLoop(std::shared_ptr<void> argument) {

    std::cout << "[SerialConsole.cpp] SerialConsole called by ON_MAIN_LOOP" << std::endl;
    THEKERNEL.CallEvent(Core::Event::ON_CONSOLE_LINE_RECEIVED, nullptr);
    
}

void Core::SerialConsole::OnIdle(std::shared_ptr<void> argument) {

    std::cout << "[SerialConsole.cpp] SerialConsole called by ON_IDLE" << std::endl;
}
