#include <stdio.h>
#include <math.h>
#include "captcha.h"

void scale_down_square(int side, int up_height,int up_array[up_height][up_height],int down_square[side][side]){

int sum=0;

int sample_side=up_height/side;


double ratio=0;
int x=0,y=0,i=0,j=0;
int a=0,b=0;

    for(x=0;x<up_height-sample_side;x=x+sample_side){
        for(y=0;y<up_height-sample_side;y=y+sample_side){
        //printf("x %d\n",x);
        //printf("y %d\n",y);
            for(i=0;i<sample_side;i++){
                for(j=0;j<sample_side;j++){
                    sum=sum+up_array[x+i][y+j];
                    
                    
//                    sums up all the pixels in the sample square to detewrmine if it is black or white
                }
            }
       
		    
		    ratio=(double)sum/sample_side*sample_side;
		    
		   	if(a < side && b < side){
				if(ratio>0.5){//if over half of the pixels in the sample box are black then the corresponding pixel in the down_square is black otherwise white.	
					down_square[a][b]=1;
				}
				else{
				    down_square[a][b]=0;
				}
				
		    }
		    b++;
		    sum=0;
        }
		b=0;
		a++;
    }
    
    
}


