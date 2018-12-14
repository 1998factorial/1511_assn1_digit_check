#include <time.h>
#include "captcha.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

  void ini_network(int neuron ,int out ,int in, double weight1[neuron][in],double weight2[out][neuron],double d_weight1[neuron][in],double d_weight2[out][neuron]){
    int i,j;
    srand(time(NULL));
    
    for(i=0;i<neuron;i++){
      for(j=0;j<in;j++){
        d_weight1[i][j] = 0;//start_change of weight1 vector with all its magnitudes equal 0
        weight1[i][j] = (float)rand()/(RAND_MAX/2)-1; //generate ramdom number between 1 and -1 for weight1 
        
      }
    }
    for(i=0;i<out;i++){
      for(j=0;j<neuron;j++){
        d_weight2[i][j] = 0;//same as d_weight1
        weight2[i][j] = (float)rand()/(RAND_MAX/2)-1;//generate ramdom number between 1 and -1 for weight2
        //printf("weight2 test %lf\n ",weight2[i][j]);
      }
    }
  }









