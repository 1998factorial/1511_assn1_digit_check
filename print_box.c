#include <stdio.h>
#include "captcha.h"

void print_box(int height, int width, int pixels[height][width]){

			int col,row;
			for(col=height-1;col>=0;col--){
				for(row=0;row<width;row++){
					if(pixels[col][row]==1){
						printf("*");
					}
					if(pixels[col][row]==0){
						printf(".");
					}
				}
				printf("\n");			
			}
		}
