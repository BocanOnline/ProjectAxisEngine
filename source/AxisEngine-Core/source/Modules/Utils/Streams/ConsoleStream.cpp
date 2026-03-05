////////////////////////////////////////////////////////////////////////////////
// organization: Bocan Online
// author: Matthew Buchanan
//
// license: The Unlicense
// project: AxisEngine
// app: AxisEngine-Core
// file: ConsoleStream.cpp
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

#include "ConsoleStream.hpp"

Core::ConsoleStream::ConsoleStream() {}

Core::ConsoleStream::~ConsoleStream() {}
       
char Core::ConsoleStream::GetChar() {

    return '\0';
}

std::string Core::ConsoleStream::GetLine() {

    // TODO
    // this is currently a blocking function
    // for the start of the program it will likely run fine, but when the end
    // of a gcode file is reached, this function will likely block all other
    // modules from executing. Likely solution is creating a stream thread to
    // watch for this input without blocking the remaining modules

    std::string line;

    std::getline(std::cin, line);
    return line;
}

bool Core::ConsoleStream::PutChar() {

    return false;
}

bool Core::ConsoleStream::PutLine() {

    return false;
}

