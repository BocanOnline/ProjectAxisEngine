//
// ProjectAxisEngine
// GcodeDispatch.cpp
//

#include <iostream>
#include <memory>

#include "../Kernel.hpp"
#include "../Module.hpp"
#include "GcodeDispatch.hpp"


Core::GcodeDispatch::GcodeDispatch() {

    std::cout << "[GcodeDispatch.cpp] GcodeDispatch created..." << std::endl;
}

Core::GcodeDispatch::~GcodeDispatch() {

    std::cout << "[GcodeDispatch.cpp] GcodeDispatch destroyed..." << std::endl;
}
    
void Core::GcodeDispatch::OnModuleLoaded() {

    this->RegisterForEvent(Core::Event::ON_CONSOLE_LINE_RECEIVED);

    std::cout << 
        "[GcodeDispatch.cpp] GcodeDispatch registered for ON_CONSOLE_LINE_RECEIVED..." 
        << std::endl;
}

void Core::GcodeDispatch::OnConsoleLineReceived(std::shared_ptr<void> argument) {

    std::cout << 
        "[GcodeDispatch.cpp] GcodeDispatch called by ON_CONSOLE_LINE_RECEIVED" 
        << std::endl; 

    THEKERNEL.CallEvent(Core::Event::ON_GCODE_RECEIVED, nullptr);
}
