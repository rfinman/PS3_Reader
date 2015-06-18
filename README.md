# PS3_READER

Repositories list is probably not complete

sudo apt-get install sixad libgtkmm-2.4-dev libsigc++-2.0-dev

To compile

    mkdir build; cd build
    cmake ..
    make

main.cpp offers an example file on how to interface
JoystickController.cpp is the controlling class

axisCallback function in Joystick controller is the way to update any 
variables. Mutexs may be required
