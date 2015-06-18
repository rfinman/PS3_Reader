#ifndef HEADER_JOYSTICKCONTROLLER_HPP
#define HEADER_JOYSTICKCONTROLLER_HPP

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

#include "joystick.h"

class JoystickController
{
private:
    std::string default_path, device_path;
    bool device_path_set;

    void axisCallback(const EventJoystick);
    void buttonCallback(const EventJoystick);
public:
    JoystickController();
    ~JoystickController();

    void setDevicePath(std::string);

    void startJoystick();
};
#endif
