//
// ProjectAxisEngine
// Actuator.hpp
//
#pragma once

#include <memory>

#include "Module.hpp"

namespace Plotter {

class Actuator : public Core::Module {

public:
    Actuator();
    virtual ~Actuator() override;
    
    virtual void OnModuleLoaded() override;

    void OnGcodeReceived(std::shared_ptr<void> argument) override;

};

} // namespace Core
