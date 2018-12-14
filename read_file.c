#include <stdio.h>
#include <stdlib.h>

void make_filename(int number, int version, char filename[15]) {

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

int main(int argc, char *argv[]){

int digit_num = 0;

while (digit_num < 10) {  
int digit_version = 0;              // For the Digits [0-9]
    while (digit_version < 100) {       // For versions [0-99]
        char filename[15];
        make_filename(digit_num, digit_version, filename);
        printf("%s",filename);
digit_version++;
    }
    digit_num++;
}

