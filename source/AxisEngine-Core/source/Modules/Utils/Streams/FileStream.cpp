////////////////////////////////////////////////////////////////////////////////
// organization: Bocan Online
// author: Matthew Buchanan
//
// license: The Unlicense
// project: AxisEngine
// app: AxisEngine-Core
// file: FileStream.cpp
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

#include "FileStream.hpp"

Core::FileStream::FileStream() {}

Core::FileStream::~FileStream() {}
       
char Core::FileStream::GetChar() {

    return '\0';
}

std::string Core::FileStream::GetLine() {

    return "\0";
}

bool Core::FileStream::PutChar() {

    return false;
}

bool Core::FileStream::PutLine() {

    return false;
}
