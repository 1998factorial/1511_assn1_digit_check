#include <stdio.h>
#include <math.h>
#include "captcha.h"

void make_square(int half_height,int half_width,int up_height,int half[half_height][half_width],int up_array[up_height][up_height]){
	int i=0,j=0;
	int k=0,l=0;
	int count=0;

	int stretch_x[half_height][up_height];
		for(i=0;i<half_height;i++){
	  		for(j=0;j<up_height;j++){
	     		stretch_x[i][j]=0;}}


    	//Extend x axis
    	for(i=0; i<half_height; i++){
        	for(j=0; j<up_height; j=j+half_height){
            	for(count=0; count<half_height; count++){
                	stretch_x[i][j+count]=half[i][k];
           		 }
       		 k++;
       		}
    	k=0;
       }

   		 //Extend y axis
   		 for(j=0; j<up_height; j++){
        	for(i=0; i<up_height; i=i+half_width){
            	for(count=0; count<half_width;count++){
                	up_array[i+count][j]=stretch_x[l][j];
           		 }
       		 l++;
        	}
    	l=0;
       }
	  }

