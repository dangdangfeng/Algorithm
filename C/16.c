/*
题目：Press any key to change color, do you want to try it. Please
hurry up!
*/

#include <stdio.h>
#include "conio.h"

int main(int argc, char const *argv[])
{
    int color;
    for(color = 0;color<8;color++){
        textbackground(color);
        cprintf("This is color %d\n",color);
        cprintf("ress any key to continue\n");
        getchar();
    }
    return 0;
}
