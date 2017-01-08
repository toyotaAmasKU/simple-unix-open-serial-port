#include <stdlib.h>

#include "serial_port.h"

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        return 1;
    }

    const char *dev = argv[1];
    const char *baud_rate_string = argv[2];
    const int baud_rate = atoi(baud_rate_string);

    int file_description;

    file_description = open_serial_port(dev);

    if(file_description == -1)
    {
        return 1;
    }

    if(set_port_attribute(file_description, baud_rate))
    {
        return 1;
    }

    close(file_description);

    return 0;
}
