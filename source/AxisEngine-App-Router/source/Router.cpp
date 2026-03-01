////////////////////////////////////////////////////////////////////////////////
// organization: Bocan Online
// author: Matthew Buchanan
//
// license: The Unlicense
// project: AxisEngine
// app: AxisEngine-App-Router
// file: Router.cpp
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <memory>

// Core Functionality
#include "AxisEngine.hpp"
#include "EntryPoint.hpp" // NOLINT

// User Added Functionality

void AxisEngine::Initialize() {
    
    std::cout << "[Router.cpp] start of Initialize()" << std::endl;

    // actuator = std::make_shared<Plotter::Module::Actuator>();
    // coolant = std::make_shared<Plotter::Module::Coolant>();
    // temperatureSensor = std::make_shared<Plotter::Module::TemperatureSensor>();

    // AxisEngine::AddModule(actuator);
    // AxisEngine::AddModule(coolant);
    // AxisEngine::AddModule(temperatureSensor);
    
    std::cout << "[Router.cpp] end of Initialize()..." << std::endl;
}
