//THis is function is extracted from cs1511 discussion group


#include <stdio.h>
#include <stdlib.h>
#include "captcha.h"

void make_filename(int num, int ver, char filename[20]) {
//this function write filename at command line

    int pointer_point = 0;

    pointer_point += sprintf(filename, "digit/");
    pointer_point += sprintf(filename + pointer_point,"%d", num);
    pointer_point += sprintf(filename + pointer_point, "_");
    if (ver < 10) {
        sprintf(filename + pointer_point, "0%d.pbm", ver);
    } else {
        sprintf(filename + pointer_point, "%d.pbm", ver);
    }
}

