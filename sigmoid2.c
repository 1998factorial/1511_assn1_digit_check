#include <stdio.h>
#include <math.h>
#include "captcha.h"
void sigmoid2(int out,double output2[out], double activated2[out]){
		int i=0;
		for(i=0;i<out;i++){
		//printf("output of %d is %lf\n",i,output2[i]);
		  activated2[i] = 1/(1+exp(-output2[i]));
		  //printf("probability of %d is %lf\n",i,activated2[i]);	// activated by sigmoid	
		}

}        // so now activated2 becomes a 10th dimension vector with each of its magnitued is the sigmoid(output2)

