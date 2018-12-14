#include <stdio.h>
#include <math.h>
#include "captcha.h"
void dot_product_layer1(int in , int neuron, double inputs[in], double weight1[neuron][in], double output1[neuron] ){
	double sum=0;
	//now we perform dot product of inputs and weight1
	int i=0,j=0;
	for(i=0;i<neuron;i++){
	  sum=0;
	  for(j=0;j<in;j++){
		sum=sum+inputs[j]*weight1[i][j]; //dot product    
	  }
	    output1[i]=sum; // output1 is the 1th magnitude = the first row of matrix inputs*weight1
	    //printf("dot product 1 %d %lf",i,output1[i]);
	}
}	

	//by now we will have the array of output1 which is a 15 dimension vector
