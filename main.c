#include <stdlib.h>
#include <fcntl.h>
#include <termios.h>

int open_serial_port(const char *dev)
{
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

    return file_description;
}

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        return 1;
    }

    const char *dev = argv[1];
    const char *baud_rate_string = argv[2];

    struct termios options;
    int file_description, baud_rate;

    file_description = open_serial_port(dev);
    baud_rate = atoi(baud_rate_string);

    if(file_description == -1)
    {
        return 1;
    }

    tcgetattr(file_description, &options);

    switch(baud_rate)
    {
        case 0:
            cfsetispeed(&options, B0);
            cfsetospeed(&options, B0);
            break;
        case 50:
            cfsetispeed(&options, B50);
            cfsetospeed(&options, B50);
            break;
        case 75:
            cfsetispeed(&options, B75);
            cfsetospeed(&options, B75);
            break;
        case 110:
            cfsetispeed(&options, B110);
            cfsetospeed(&options, B110);
            break;
        case 134:
            cfsetispeed(&options, B134);
            cfsetospeed(&options, B134);
            break;
        case 150:
            cfsetispeed(&options, B150);
            cfsetospeed(&options, B150);
            break;
        case 200:
            cfsetispeed(&options, B200);
            cfsetospeed(&options, B200);
            break;
        case 300:
            cfsetispeed(&options, B300);
            cfsetospeed(&options, B300);
            break;
        case 600:
            cfsetispeed(&options, B600);
            cfsetospeed(&options, B600);
            break;
        case 1200:
            cfsetispeed(&options, B1200);
            cfsetospeed(&options, B1200);
            break;
        case 1800:
            cfsetispeed(&options, B1800);
            cfsetospeed(&options, B1800);
            break;
        case 2400:
            cfsetispeed(&options, B2400);
            cfsetospeed(&options, B2400);
            break;
        case 4800:
            cfsetispeed(&options, B4800);
            cfsetospeed(&options, B4800);
            break;
        case 9600:
            cfsetispeed(&options, B9600);
            cfsetospeed(&options, B9600);
            break;
        case 19200:
            cfsetispeed(&options, B19200);
            cfsetospeed(&options, B19200);
            break;
        case 38400:
            cfsetispeed(&options, B38400);
            cfsetospeed(&options, B38400);
            break;
        case 57600:
            cfsetispeed(&options, B57600);
            cfsetospeed(&options, B57600);
            break;
        //case 76800:
        //    cfsetispeed(&options, B76800);
        //    cfsetospeed(&options, B76800);
        //    break;
        case 115200:
            cfsetispeed(&options, B115200);
            cfsetospeed(&options, B115200);
            break;
        default:
            return 1;
    }

    options.c_cflag |= (CLOCAL | CREAD);

    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;

    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

    options.c_iflag &= ~(IXON | IXOFF | IXANY);

    options.c_iflag &= ~OPOST;

    tcsetattr(file_description, TCSANOW, &options);

    close(file_description);

    return 0;
}
