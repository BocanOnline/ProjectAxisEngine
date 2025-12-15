//
// ProjectAxisEngine
// main.cpp
//

#include <iostream>
#include <memory>

// Core Functionality
#include "Kernel.hpp"

// User Added Functionality
#include "Modules/Actuator.hpp"

void init() {
    
    std::cout << "[main.cpp] start of init()" << std::endl;
   
    // Only the user code modules need to be added in the main file.
    // The core code modules are added in Kernel.cpp.
    std::shared_ptr<Plotter::Actuator> actuator;
    actuator = std::make_shared<Plotter::Actuator>();
    THEKERNEL.AddModule(actuator);
    
    // I am pleased with this functionality that the user can add their own
    // modules relatively seamlessly. I want to add this same functionality for
    // events in the future so a user could add their own events if they wanted
    // to without modifying the Core code. An obvious limitation is user added 
    // events would only be called and listened to by user modules.

    std::cout << "[main.cpp] end of init()..." << std::endl;
}

int main(int argc, char** argv) {

    std::cout << "[main.cpp] start of main function..." << std::endl;
    
    init();

    THEKERNEL.Run();
    
    std::cout << "[main.cpp] end of main function..." << std::endl;
    return 0;
}
