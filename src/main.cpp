#include "JoystickController.hpp"

static void usage(const char* progname)
{
    fprintf (stderr, "Usage: %s [options]\n"
            "\n"
            "Options:\n"
            "  -p (path)   Specify joystick path. Default /dev/input/js1\n"
            "  -h              This help message.\n"
            , progname);
    exit(1);
}

int main(int argc, char** argv)
{
    int c;

    bool file = false;
    std::string path;
    while (( c = getopt(argc, argv, "hp:")) >= 0)
    {
        switch (c) {
            case 'p':
                file = true;
                path.insert(0,optarg);
                std::cout<<"Using user specified path "<<path<<std::endl;
                break;
            case 'h':
            default:
                usage(argv[0]);
                break;
        }
    }

    JoystickController joystick1;

    if (file)
        joystick1.setDevicePath(path);

    joystick1.startJoystick();

    return 0;

}
