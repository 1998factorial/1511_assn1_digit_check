#include <stdio.h>
#include <math.h>
#include "captcha.h"

void update_weights( int neuron, int in, int out,double d_weight1[neuron][in], double d_weight2[out][neuron], double weight1[neuron][in], double weight2[out][neuron],double activated1[neuron],double activated2[out], int desired_output[out], double inputs[in]){
			int i,j;
			double a;//accumulated value by chain rule
			double learning_rate1=0.125;
			double learning_rate2=0.1;
			double learning_rate3=0.125;
			double learning_rate4=0.1;
		for(i=0;i<neuron;i++){
		  a=0;
		  for(j=0;j<out;j++){
		  a=a+(activated2[j]-desired_output[j])*weight2[j][i];//accumulated partial derivative 
		  d_weight2[j][i]=learning_rate1*d_weight2[j][i]+learning_rate2*(activated2[j]-desired_output[j])*activated1[i];//change of weight2	  
		  weight2[j][i]=weight2[j][i]-d_weight2[j][i];//update new value of weight2	
		  //printf("change of weight2 %lf\n", d_weight2[j][i]);  
		  }		  
		  for(j=0;j<in;j++){
		  d_weight1[i][j]=learning_rate3*d_weight1[i][j]+learning_rate4*a*activated1[i]*(1-activated1[i])*inputs[j];//change of weight1
		  weight1[i][j]=weight1[i][j]-d_weight1[i][j];//update new value of weight1	
		  //printf("change of weight1 %lf\n", d_weight1[i][j]);
		  	  
		  }		
		}
}
