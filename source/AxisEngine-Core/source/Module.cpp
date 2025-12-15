//
// ProjectAxisEngine
// Module.cpp
//

#include "Kernel.hpp"
#include "Module.hpp"

void Core::Module::RegisterForEvent(Core::Event event) {

    THEKERNEL.RegisterForEvent(event, shared_from_this());
}

