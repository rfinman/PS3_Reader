#include "JoystickController.hpp"

JoystickController::JoystickController():device_path_set(false),
                                         default_path("/dev/input/js0")
{}

JoystickController::~JoystickController(){}

void JoystickController::setDevicePath(std::string path)
{
    device_path.clear();
    device_path.insert(0,path);
    device_path_set = true;
}

void JoystickController::axisCallback(const EventJoystick eventJoy)
{
    //eventJoy.time is the time
    //enentJoy.value is the value of the axis
    //eventJoy.number is the axes number
    switch (eventJoy.number)
    {
        case LEFT_VERTICAL:
            break;
        case LEFT_HORIZONTAL:
            break;
        case RIGHT_HORIZONTAL:
            break;
        case RIGHT_VERTICAL:
            break;
        case IMU_ROLL:
            //printf("IMU_ROLL %d", eventJoy.value);
            break;
        case IMU_PITCH:
            //printf("IMU_PITCH %d\n", eventJoy.value);
            break;
        case IMU_YAW:
            //printf("IMU_YAW %d\n", eventJoy.value);
            break;
    }
}

void JoystickController::startJoystick()
{
    if (!device_path_set)
    {
        std::cout<<"No path set, using default "<<default_path<<std::endl;
        this->setDevicePath(default_path);
    }

    Joystick joystick;

    EventJoystick m_eventButton;
    EventJoystick m_eventAxis;

    joystick.open(device_path);

    int numButtons = joystick.getNumberOfButtons();
    int numAxis = joystick.getNumberOfAxes();
    std::cout << "Joystick: "<<joystick.getIdentifier()<<std::endl;

    joystick.signalAxis.connect(sigc::mem_fun(*this, &JoystickController::axisCallback));
    // TODO Set up buttons if needbe

    pause();
}
