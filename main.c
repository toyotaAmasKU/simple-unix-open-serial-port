#include <fcntl.h>

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        return 1;
    }

    const char *dev = argv[1];

    int file_description;

    file_description = open(dev, O_RDWR | O_NOCTTY | O_NDELAY);
    
    if(file_description == -1)
    {
        return -1;
    }
    else
    {
        fcntl(file_description, F_SETFL, FNDELAY);
    }

    return 0;
}
