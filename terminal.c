#include<stdio.h>
#include<termios.h>
#include"terminal.h"

/* This function disables buffering (echo and canon) in terminal input */
void disableBuffer()
{
    struct termios mode;

    tcgetattr(0, &mode);
    mode.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(0, TCSANOW, &mode);
}

/* This function enables buffering (echo and canon) in terminal input */
void enableBuffer()
{
    struct termios mode;

    tcgetattr(0, &mode);
    mode.c_lflag |= (ECHO | ICANON);
    tcsetattr(0, TCSANOW, &mode);
}
