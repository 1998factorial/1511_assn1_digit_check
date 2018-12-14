#include <stdio.h>
#include <math.h>
#include "captcha.h"
void dot_product_layer2(int out, int neuron,double output2[out],double weight2[out][neuron],double activated1[out] ){
		int i=0,j=0;
		double sum=0;
		// perform dot product for weight2 and activated1
		for(i=0;i<out;i++){
		  sum=0;
		  for(j=0;j<neuron;j++){
		    sum=sum+weight2[i][j]*activated1[j];//dot product
		  }
		  output2[i]=sum;// each magnitude in output2 (10 th dimension vector) will be equal to the corresbonding row of the weight2*activated
		} 
}
