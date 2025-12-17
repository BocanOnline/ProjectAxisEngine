//
// ProjectAxisEngine
// Plotter.cpp
//

#include <iostream>
#include <memory>

// Core Functionality
#include "AxisEngine.hpp"

// User Added Functionality
#include "Modules/Actuator.hpp"

void AxisEngine::Initialize() {
    
    std::cout << "[Plotter.cpp] start of Initialize()" << std::endl;
   
    std::shared_ptr<Plotter::Actuator> actuator = std::make_shared<Plotter::Actuator>();
    AxisEngine::AddModule(actuator);
    
    std::cout << "[Plotter.cpp] end of Initialize()..." << std::endl;
}
