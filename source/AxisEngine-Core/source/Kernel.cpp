//
// ProjectAxisEngine
// Kernel.cpp
//

#include <iostream>

#include "Kernel.hpp"
#include "Module.hpp"
#include "Modules/SerialConsole.hpp"
#include "Modules/GcodeDispatch.hpp"
#include "Modules/SlowTicker.hpp"
#include "Modules/Robot.hpp"
#include "Modules/Conveyer.hpp"

Core::Kernel Core::Kernel::s_Instance;

Core::Kernel::Kernel() {
   
    std::cout << "[Kernel.cpp] Kernel created..." << std::endl; 
    std::cout << "[Kernel.cpp] Kernel constructor start..." << std::endl;
    serialconsole = std::make_shared<SerialConsole>();
    gcodedispatch = std::make_shared<GcodeDispatch>();
    slowticker    = std::make_shared<SlowTicker>();
    robot         = std::make_shared<Robot>();
    conveyer      = std::make_shared<Conveyer>();
   
    Core::Kernel::AddModule(serialconsole);
    Core::Kernel::AddModule(gcodedispatch);
    Core::Kernel::AddModule(slowticker);
    Core::Kernel::AddModule(robot);
    Core::Kernel::AddModule(conveyer);
    std::cout << "[Kernel.cpp] Kernel constructor end..." << std::endl; 

//    after these below function calls are implemented, I may move them to
//    the start of Run() to allow time to load the user modules before starting
//    any runtimes.
//    conveyer.start(robot.GetNumberRegisteredMotors());
//    slowticker.start();
}

Core::Kernel::~Kernel() {
    
    std::cout << "[Kernel.cpp] Kernel destroyed..." << std::endl;
}

void Core::Kernel::Run() {

    Core::Kernel::Get().CallEvent(Core::Event::ON_MAIN_LOOP, nullptr);
    Core::Kernel::Get().CallEvent(Core::Event::ON_IDLE, nullptr);
}

void Core::Kernel::AddModule(std::shared_ptr<Module> module) {
    
    std::cout << "[Kernel.cpp] Module added..." << std::endl;
    module->OnModuleLoaded(); 
    
}

void Core::Kernel::RegisterForEvent(Core::Event event, std::shared_ptr<Module> module) {

    m_Hooks.at(static_cast<int>(event)).push_back(module); 
}

bool Core::Kernel::HasEvent(Core::Event event, std::shared_ptr<Module> module) {

    return true;
}

void Core::Kernel::CallEvent(Core::Event event, std::shared_ptr<void> argument) {

    for (auto module : m_Hooks.at(static_cast<int>(event))) {
        
        switch(event) {
            case Core::Event::ON_MAIN_LOOP:
                std::cout << "[Kernel.cpp] Event Called: ON_MAIN_LOOP" << std::endl;
                module->OnMainLoop(argument);
                break;
            case Core::Event::ON_CONSOLE_LINE_RECEIVED:
                std::cout << "[Kernel.cpp] Event Called: ON_CONSOLE_LINE_RECEIVED" << std::endl;
                module->OnConsoleLineReceived(argument);
                break;
            case Core::Event::ON_GCODE_RECEIVED:
                std::cout << "[Kernel.cpp] Event Called: ON_GCODE_RECEIVED" << std::endl;
                module->OnGcodeReceived(argument);
                break;
            case Core::Event::ON_IDLE:
                std::cout << "[Kernel.cpp] Event Called: ON_IDLE" << std::endl;
                module->OnIdle(argument);
                break;
            case Core::Event::ON_SECOND_TICK:
                std::cout << "[Kernel.cpp] Event Called: ON_SECOND_TICK" << std::endl;
                module->OnSecondTick(argument);
                break;
            case Core::Event::ON_GET_PUBLIC_DATA:
                std::cout << "[Kernel.cpp] Event Called: ON_GET_PUBLIC_DATA" << std::endl;
                module->OnGetPublicData(argument);
                break;
            case Core::Event::ON_SET_PUBLIC_DATA:
                std::cout << "[Kernel.cpp] Event Called: ON_SET_PUBLIC_DATA" << std::endl;
                module->OnSetPublicData(argument);
                break;
            case Core::Event::ON_HALT:
                std::cout << "[Kernel.cpp] Event Called: ON_HALT" << std::endl;
                module->OnHalt(argument);
                break;
            case Core::Event::ON_ENABLE:
                std::cout << "[Kernel.cpp] Event Called: ON_ENABLE" << std::endl;
                module->OnEnable(argument);
                break;
            case Core::Event::NUMBER_OF_DEFINED_EVENTS:
            default:
                std::cerr << "[Kernel.cpp] Error: unregistered event call" << std::endl;
        }
    }
}
