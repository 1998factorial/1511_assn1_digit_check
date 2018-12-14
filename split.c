#include <stdio.h>
#include <stdio.h>

void get_slice(int height, int width, int pixels[height][width], int *startFrom, int *rightBound){




int i,j;
int previous=0;
int startFromTrue=0;
int rightBoundTrue=0;


    for(j = *startFrom; j<width; j++){
        for(i = 0; i<height;i++){
            if(pixels[i][j]==1 && previous ==1 && startFromTrue==0){
                *startFrom=j;
                startFromTrue=1;
                break;
            }
            else{
                previous=1;
            }
        }
        if(startFromTrue==1){
            break;
        }
    }
previous=0;
int col_sum=0;

    for(j = *startFrom; j<width; j++){
        for(i = 0; i<height;i++){
            col_sum=col_sum + pixels[i][j];
        }
        if(j==width-1){
            *rightBound=j+1;
        }

        else if(col_sum==0){
            *rightBound=j;
            break;
        }
        else{
            col_sum=0;
        }

    }
}

