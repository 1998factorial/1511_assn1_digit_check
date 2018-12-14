//Edward Lu assignment1 
/*
This assignment is about using nerual network to recognise hand written digits 
Reference to http://neuralnetworksanddeeplearning.com/

This assignment "crack_digit" has two parts
part1.training
part1 is based on the algorithm "gradient decent",which involves the concept of backpropagation
Such algorithm allows the weights for each inputs(in this case,pixels)to be adjusted. The amount of weights needed to be changed can be obtain by partial drevative. And the loop of updating weights is called training.
When training is finished, weights in both layers will be recorded into two files(weights1final.txt & weights2final.txt)

part2.making decision
by using the optimized weights gained in training, using forward propagation to make decision.

*/
#include <stdio.h>
#include <math.h>
#include "captcha.h"
#include<stdlib.h>
#define neuron 40 // number of neurons in hidden layer
#define in 625  //size of input pixels
#define out 10  //output size
#define train_times 1  //training time (My optimized weights are recorded after a 30 times of training)
#define side 25

int main(int argc, char *argv[]){
    int height=0, width=0, start_row=0, start_column=0, box_width=0, box_height=0;   
	int center_x=0,center_y=0;
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        return 1;
    }


        //firstly we set up our weights by generating random numbers between -1 to 1 before training 
        
        double d_weight1[neuron][in] = {{0.0}};//the derivitive of c/weight2
        double d_weight2[out][neuron] = {{0.0}};//the derivitive of c/weight2  
    
        double weight1[neuron][in] = {{0.0}};//weight in layer1
        double weight2[out][neuron] = {{0.0}};//weight in layer2


//The following part is the training part, which has been commented by me. Since weights have been saved there is no need to perform training anymore. However, if you would like to see how i train it, just delate the comment for training part and make the bottom part(the actual making decision part comment.), compile it with update_weight function and run it.
        
 
        ini_network(neuron,out,in,weight1,weight2,d_weight1,d_weight2);
        //initialize weight1 and weight2
        
//training start


		int digit_version,loop,digit_num;

        char filename[20];
		int count1;
		count1=1;
		
    	int correct=0;

for(loop=0;loop<train_times;loop++){	// training loop 
		    count1++;	    
    for(digit_version=0;digit_version<450;digit_version++){		// 0...99
    	for(digit_num=0;digit_num<10;digit_num++){		//0 ... 9
    				
    	            	
        make_filename(digit_num, digit_version, filename);// a function which writes file name
		printf("%s\n",filename);  

		//Get Dimensions
    	get_pbm_dimensions(filename, &height, &width);
    	int pixels[height][width];


		//Populate original array
    	read_pbm(filename, height, width, pixels);
    	
    
        get_bounding_box(height, width, pixels, &start_row, &start_column, &box_height, &box_width);//bound the pattern
		
		//printf("width %d\n",box_width);
		
        int box_pixels[box_height][box_width];//an array which stores the box
        
        copy_pixels(height, width, pixels, start_row, start_column, box_height, box_width, box_pixels);//get array for box
        
        int half_height=box_height/2;
    	int half_width=box_width/2;
    	
    	int half[half_height][half_width];
    	//Now half the image;
    	       
        half_image(box_height,box_width,half_height,half_width,box_pixels,half);//half the size of the box
        
        
        int up_height=half_height*half_width;//make it a square
        int up_array[up_height][up_height];
        
        make_square(half_height,half_width,up_height,half,up_array);//make the halfed size box a large square
      
        int down_square[side][side]={{0}};       
       
        scale_down_square(side,up_height,up_array,down_square);
        
        
        //scales the huge square to a 25x25 size of square
        //do scaling here.        
        //We change the values of white pixels to -1.
        //So that the process of gradient descent will be faster.
        
        
        int back_up[side][side];
        int i, j;
        for(i=0;i<side;i++){
          for(j=0;j<side;j++){
            if(down_square[i][j]==0){
              back_up[i][j]=-1;
            }
            if(down_square[i][j]==1){
              back_up[i][j]=1;
              }
          }
        }
  		//Here we change the two dimensional array of back_up to a one dimensional array inputs 
  		double inputs[in];//input pixels, black pixels represent 1, white pixels represent -1       
        int k=0;
        while(k<in){
          for(i=0;i<side;i++){
            for(j=0;j<side;j++){
			  //inputs[k]=down_square[i][j];
			  if(down_square[i][j]==1){
			  	inputs[k]=1.0;
			  }
			  else{
			  	inputs[k]=-1.0;
			  }            
              k++;
            }
          }
        }
        
        //now the 625 (25x25) th dimension vector(array) of inputs has been set up
        

       	//double epsilon=0.01;
        

        //desired_output is used during training 
        
        int desired_output[out]={0,0,0,0,0,0,0,0,0,0};//desired result eg. {1,0,0,0,0,0,0,0,0,0} a 10th vector which represents the desired outcome.
        
        desired_output[digit_num]=1; 
        
        //only during training. only used in training, not using in actual autotest.
        
        double output1[neuron];//after weight1*input
        double output2[out];//after weight2*activated1             
        double activated1[neuron];// sigmoid(output1)
        double activated2[out];// sigmoid(output2)  sigmoid: 1/(1+exp(-x))
       
        // then we need to do training for network, reducing the value of cost function, by changing the weights in both layers
        // C = 0.5*(activated2 - desired_output)^2  they are both 10th dimension vectors        
        // first of all we need to perform dot product.
        //we have inputs and weight1 so output1=inputs dot weight1
        //2
        
        
        dot_product_layer1(in,neuron,inputs, weight1, output1);
        
        
        // we will have the array for output1 which is a 15th dimension vector
        
        //activate the layer1 neurons by using sigmoid function
        //3     
        
        
        sigmoid1(neuron,output1, activated1);
        
        
        
        //activated1 done
        
        
        // perform dot product again for layer2
        
        // output2 = weight2 dot activated1
        //4
        
        
        dot_product_layer2(out,neuron,output2, weight2, activated1);
        
        
        // after this operation, output2[out] which is a 10 th dimension vector will be assigned 
        
        
        
        // then we put the output2 vector into the sigmoid function so it will turn to activated2
        
        
        //5
        
        
        sigmoid2(out,output2, activated2);
        
        // after this operation activated2 = [a1,a2,a3,a4,a5,a6,a7,a8,a9,a10]
        //each ak  0<=k<=10 is a float between 1 and 0
        //each output represents the probability of the possible digit
        //if the activated2=[0,0.99,0,0,0,0,0,0,0.01] then the predition made by the network is digit "1"
        //now we need perform cost function 
        //C=0.5*(activated2 - desired_output)^2
        //by finding the minmum value of cost function, we can make the best prediction
        // optimizing the cost value is called the backpropagation
        //by achieveing this we need to find the change amount of weights 
        //so we need to use gradient descent
        
		    double cost[out];   
		    
		         
		    //6
		    cost_function(out,desired_output,activated2,cost);
		    
		    
		    
		    //after this operation,  specfic cost in each dimension will be claculated and stored into the array cout[output], each deviation for the probabity of each number will be printed out , so making it easy to supervise the training.
		    
		    
		           
		    //Now, we are performing backpropagation
		    //To achieve this, we need to find the change of weights in both layers
		    
		    //7
		    
		    
		    update_weights(neuron, in, out,d_weight1, d_weight2 , weight1, weight2, activated1, activated2, desired_output,inputs);
		    
		    
		    //weight1 and weight2 are updated after this operation
		    

		//Making decision 
		
		int digit=0;
		double greatest=0.0;
		    for(i=0;i<out;i++){//to find out which digit has the highest probability
		        if(activated2[i]>greatest){
		            greatest=activated2[i];
		            digit=i;
		        }
		    }

		if(digit==digit_num){
		    correct++;//during training this is used to determine the amount of the correct predictions
		}

		printf("This digit is %d\n",digit);
        	}
        }
   }
   
  
  
  
   // this operation allows the weight1 and weight2 to be recoreded into two txt files after training
   int i,j;
   
		   		FILE *f1,*f2;//file pointers
				f1 = fopen("weights1finalxx.txt", "w");		
		
				// it was f1 = fopen("weights1final.txt","w");
				// but weights in this file have already been optimized so there is no need to rewrite it anymore.
				//open file weight1.txt and write

				for (i = 0; i < neuron; i++){
					for (j = 0; j < in; j++){
						fprintf(f1, "%.16g\n", weight1[i][j]);
					}
				}
				fclose(f1);//close file 

					f2 = fopen("weights2finalxx.txt", "w");

				for (i = 0; i < out; i++){
					for (j = 0; j < neuron; j++){
						fprintf(f2, "%.16g\n", weight2[i][j]);
					}
				}

				fclose(f2); 
		//training finish  
		

		
		double percent=correct/(train_times*4.5*10.00);
		printf("times get correctly %d\n",correct);
		printf("%lf Percent \n",percent);
		

  
   //allowing the weights to be reused in the future.
   //this operation allows the program to scan the data in the exist files weight1.txt and weight2.txt,(which have the weights generated during training ) therefore,allowing this program to make predition without training.
   
      
  
  
   //The following content is activated when training is finished and the final weights have been recorded into txt files.
   
  /*
 
		   int j=0,i=0;
		   FILE *f1,*f2;//file pointers
		   
		   f1 = fopen("weights1final.txt","r");//open file and read
		   
		   for(i=0;i<neuron;i++){
		   		for(j=0;j<in;j++){
		   			char cha_num1[30];
		   			fgets(cha_num1,30,f1);
		   			weight1[i][j]=atof(cha_num1);//fill weight1 array with the optimized data
		   		}
		   }
		   fclose(f1);
		   
		   f2 = fopen("weights2final.txt","r");//open file and read
		   
		   for(i=0;i<out;i++){
		   		for(j=0;j<neuron;j++){
		   			char cha_num2[30];
		   			fgets(cha_num2,30,f2);
		   			weight2[i][j]=atof(cha_num2);
		   		}
		   }
		   fclose(f2);
		   
   //Get Dimensions
    	get_pbm_dimensions(argv[1], &height, &width);
    	int pixels[height][width];


		//Populate original array
    	read_pbm(argv[1], height, width, pixels);
    	    
        get_bounding_box(height, width, pixels, &start_row, &start_column, &box_height, &box_width);//bound the pattern

        int box_pixels[box_height][box_width];//an array which stores the box
        
        copy_pixels(height, width, pixels, start_row, start_column, box_height, box_width, box_pixels);//get array for box
        
        int half_height=box_height/2;
        
    	int half_width=box_width/2;
    	
    	int half[half_height][half_width];
    	int x=0,y=0;
    	for(x=0;x<half_height;x++){
    		for(y=0;y<half_width;y++){
    			half[x][y]=0;   	
    		}
    	}
    	//Now half the image;
    	       
        half_image(box_height,box_width,half_height,half_width,box_pixels,half);//half the size of the box
       
       
        
        int up_height=half_height*half_width;//make it a square
        
        int up_array[up_height][up_height];
        
        make_square(half_height,half_width,up_height,half,up_array);//make the halfed size box a large square
        
        
        
        int down_square[side][side] = {{0}};       
       	//print_box(side,side,down_square);
        
       
        scale_down_square(side,up_height,up_array,down_square);
        //print_box(side,side,down_square);
        
        
        
        
        
  		//Here we change the two dimensional array of back_up to a one dimensional array inputs 
  		double inputs[in]={0.0};//input pixels, black pixels represent 1, white pixels represent 0
  		
  		
  		
  		
  		       
        int k=0;
        while(k<in){
          for(i=0;i<side;i++){
            for(j=0;j<side;j++){
			  //inputs[k]=down_square[i][j];
			  if(down_square[i][j]==1){
			  	inputs[k]=1.0;
			  }
			  else{
			  	inputs[k]=-1.0;
			  }            
              k++;
            }
          }
        }
        

        double output1[neuron]={0.0};//after weight1*input
        
        double output2[out]={0.0};//after weight2*activated1    
                 
        double activated1[neuron]={0.0};// sigmoid(output1)
        
        double activated2[out]={0.0};// sigmoid(output2)  sigmoid: 1/(1+exp(-x))
       
        dot_product_layer1(in,neuron,inputs, weight1, output1);
    
        sigmoid1(neuron,output1, activated1);
        
        dot_product_layer2(out,neuron,output2, weight2, activated1);
        
        sigmoid2(out,output2, activated2);
               
        //double cost[out];        
        
        //cost_function(out,desired_output,activated2,cost);


        //Get digit
    int digit=0;
    double greatest=0.0;
        for(i=0;i<out;i++){//to find out which digit has the highest probability
            if(activated2[i]>greatest){
                greatest=activated2[i];
                digit=i;
            }
        }
        printf("%d\n",digit);//make prediction
*/
    return 0;
}
		
