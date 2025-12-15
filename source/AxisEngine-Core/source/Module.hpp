//
// ProjectAxisEngine
// Module.hpp
//
#pragma once

#include <memory>

namespace Core {

    enum class Event {
   
        ON_MAIN_LOOP,
        ON_CONSOLE_LINE_RECEIVED,
        ON_GCODE_RECEIVED,
        ON_IDLE,
        ON_SECOND_TICK,
        ON_GET_PUBLIC_DATA,
        ON_SET_PUBLIC_DATA,
        ON_HALT,
        ON_ENABLE,
        NUMBER_OF_DEFINED_EVENTS,
    };

class Module : public std::enable_shared_from_this<Module>{

public:
    Module() {}
    virtual ~Module() = default;
    
    virtual void OnModuleLoaded() = 0;

    void RegisterForEvent(Core::Event);

    virtual void OnMainLoop(std::shared_ptr<void> argument) {}
    virtual void OnConsoleLineReceived(std::shared_ptr<void> argument) {}
    virtual void OnGcodeReceived(std::shared_ptr<void> argument) {}
    virtual void OnIdle(std::shared_ptr<void> argument) {}
    virtual void OnSecondTick(std::shared_ptr<void> argument) {}
    virtual void OnGetPublicData(std::shared_ptr<void> argument) {}
    virtual void OnSetPublicData(std::shared_ptr<void> argument) {}
    virtual void OnHalt(std::shared_ptr<void> argument) {}
    virtual void OnEnable(std::shared_ptr<void> argument) {}

};

} // namespace Core
