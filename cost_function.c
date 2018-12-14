#include <stdio.h>
#include <math.h>
#include "captcha.h"

void cost_function(int out,int desired_output[out], double activated2[out],double cost[out]){
		int i=0;
		double sum=0;
		
		for(i=0;i<out;i++){
		  cost[i]=0.5*(desired_output[i]-activated2[i])*(desired_output[i]-activated2[i]);//cost for each magnitude in its corresponding dimension
		  sum=sum+cost[i];		  
		  //printf("error in gussing number %d %.10lf\n",i,cost[i]);
		  //printf("cost for number %d is %.10lf\n ",i,cost[i]);
		  printf("probability for guessing number %d is %lf\n",i,activated2[i]);
		}
		
		  //printf("Average error: %lf\n",sum/out);
}
