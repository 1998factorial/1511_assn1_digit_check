#include <stdio.h>
#include <math.h>
#include "captcha.h"

void half_image(int box_height,int box_width,int half_height,int half_width,int box_pixels[box_height][box_width],int half[half_height][half_width]){
	int i=0,j=0;
int sum=0;


int k=0, l=0;
//printf("half height%d\n",half_height);
//printf("half width%d\n",half_width);
    for(i=0;i<box_height-1;i=i+2){
        for(j=0; j<box_width-1; j=j+2){
            sum= sum + box_pixels[i][j] + box_pixels[i+1][j] + box_pixels[i][j+1] + box_pixels[i+1][j+1];
            
            if(sum>3){//to determine if the pixel in the new box is black or not
                half[k][l]=1;
            }
            else{
                half[k][l]=0;
            }
            //printf("%d\n",half[k][l]);
            l++;
            sum=0;
        }
    l=0;
    k++;
    }

}
