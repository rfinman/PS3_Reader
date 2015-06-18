/*#ifndef HEADER_MAIN_HPP
#define HEADER_MAIN_HPP

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

#include "joystick.h"

class Main
{
private:
    std::string device_path;

    void axisCallback(const EventJoystick);
    void buttonCallback(const EventJoystick);
public:
    Main(std::string);
    ~Main();

    void startJoystick();
};
#endif
*/
