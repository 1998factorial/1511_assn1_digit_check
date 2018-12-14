#include <stdio.h>
#include <math.h>
#include "captcha.h"
void sigmoid1(int neuron, double output1[neuron],double activated1[neuron]){
	int i=0;
	// output1 and activated have same dimension
	
	for(i=0;i<neuron;i++){
	  activated1[i] = 1/(1+exp(-output1[i]));
	  //printf("activated %lf\n",activated1[i]);
	}
    // by now, all magnitudes in activated1 are numbers between 0 and 1.
}
