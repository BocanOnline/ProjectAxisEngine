//
// ProjectAxisEngine
// Kernel.hpp
//
#pragma once

#include <array>
#include <vector>
#include <memory>

#include "Module.hpp"

#define THEKERNEL Core::Kernel::Get()

namespace Core {

class SerialConsole;
class GcodeDispatch;
class SlowTicker;
class Robot;
class Conveyer;

class Kernel {

public:
    static Kernel& Get() { return s_Instance; } 

    void Run();

    void AddModule(std::shared_ptr<Module> module);
    void RegisterForEvent(Core::Event event, std::shared_ptr<Module> module);
    bool HasEvent(Core::Event event, std::shared_ptr<Module> module);
    void CallEvent(Core::Event event, std::shared_ptr<void> argument);

public:
    std::shared_ptr<SerialConsole> serialconsole;
    std::shared_ptr<GcodeDispatch> gcodedispatch;
    std::shared_ptr<SlowTicker>    slowticker;
    std::shared_ptr<Robot>         robot;
    std::shared_ptr<Conveyer>      conveyer;

private:
     Kernel(); 
     Kernel(const Core::Kernel&) = delete;
    ~Kernel();

private:
    static Kernel s_Instance;
    
    std::array<std::vector<std::shared_ptr<Module>>, 
        static_cast<int>(Core::Event::NUMBER_OF_DEFINED_EVENTS)> m_Hooks;
    
    // m_Hooks is an array of vectors storing the address of registered modules for each event.
    //
    // Array (Columns) m_Hooks
    // Vectors (Rows, one for each defined event)
    // 0 (ON_MAIN_LOOP): SerialConsole, GcodeDispatcher, Robot, ... 
    // 1 (ON_CONSOLE_LINE_RECEIVED): GcodeDispatcher 
    // 2 (ON_GCODE_RECEIVED): Robot, Conveyer, ...
    // 3 (ON_IDLE): SerialConsole, Robot, Conveyer, ...
    // ...

    // TODO: add config data/methods

};

} // namespace Core
