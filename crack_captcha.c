//For the crack_captcha, we treat each image as a combination of 4 digits
//THerefore, once we seperate each of them, there will bw no diffrerence from crack_digit.
//By Edward lu
#include <stdio.h>
#include <math.h>
#include "captcha.h"
#include<stdlib.h>
#define neuron 40 // number of neurons in hidden layer
#define in 625  //size of input pixels
#define out 10  //output size
#define train_times 1  //training time
#define side 25

int main(int argc, char *argv[]){
    int height=0, width=0, start_row=0, start_column=0, box_width=0, box_height=0;   
	
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        return 1;
    }

  
        double weight1_1[neuron][in] = {{0.0}};//weight in layer1
        double weight1_2[neuron][in] = {{0.0}};
        double weight1_3[neuron][in] = {{0.0}};
        double weight1_4[neuron][in] = {{0.0}};
        
        double weight2_1[out][neuron] = {{0.0}};//weight in layer2
        double weight2_2[out][neuron] = {{0.0}};
        double weight2_3[out][neuron] = {{0.0}};
        double weight2_4[out][neuron] = {{0.0}};
        
        
        int j=0,i=0;
		   FILE *f1,*f2;//file pointers
		   
		   f1 = fopen("weights1final.txt","r");//open file and read
		   
		   for(i=0;i<neuron;i++){
		   		for(j=0;j<in;j++){
		   			char cha_num1[30];
		   			fgets(cha_num1,30,f1);
		   			weight1_1[i][j]=atof(cha_num1);
		   			weight1_2[i][j]=atof(cha_num1);
		   			weight1_3[i][j]=atof(cha_num1);
		   			weight1_4[i][j]=atof(cha_num1);
		   			
		   		}		   		
		   }	
		   fclose(f1);
		   
		   f2 = fopen("weights2final.txt","r");//open file and read
		   
		   for(i=0;i<out;i++){
		   		for(j=0;j<neuron;j++){
		   			char cha_num2[30];
		   			fgets(cha_num2,30,f2);
		   			weight2_1[i][j]=atof(cha_num2);
		   			weight2_2[i][j]=atof(cha_num2);
		   			weight2_3[i][j]=atof(cha_num2);
		   			weight2_4[i][j]=atof(cha_num2);
		   			
		   		}
		   }
		   fclose(f2);
		   
		   //The above operation fills the weights arrays with the data in files. Data was generated during training.
		   
   		//Get Dimensions
    	get_pbm_dimensions(argv[1], &height, &width);
    	
    	
    	int pixels[height][width];
		
		
		//Populate original array
    	read_pbm(argv[1], height, width, pixels);
    	
    	//Split the whole captcha image into four boxes.
    	int firstStartCol=0,firstFinishCol=0;
    	int secondStartCol=0,secondFinishCol=0;
    	int thirdStartCol=0,thirdFinishCol=0;
    	int lastStartCol=0,lastFinishCol=0;    	
    	chopToFour(height,width,pixels,&firstStartCol,&firstFinishCol,&secondStartCol,&secondFinishCol,&thirdStartCol,&thirdFinishCol,&lastStartCol,&lastFinishCol);
    	
    	int width1=firstFinishCol-firstStartCol+1;
    	int width2=secondFinishCol-secondStartCol+1;
    	int width3=thirdFinishCol-thirdStartCol+1;
    	int width4=lastFinishCol-lastStartCol+1;
    	
    	int part1[height][width1];
    	int part2[height][width2];
    	int part3[height][width3];
    	int part4[height][width4];
    	int startRow=0;
    	copy_pixels(height, width, pixels, startRow, firstStartCol, height, width1, part1);
    	copy_pixels(height, width, pixels, startRow, secondStartCol, height, width2, part2);
    	copy_pixels(height, width, pixels, startRow, thirdStartCol, height, width3, part3);
    	copy_pixels(height, width, pixels, startRow, lastStartCol, height, width4, part4);
    	int start_row1=0, start_column1=0, box_height1=0, box_width1=0;
    	int start_row2=0, start_column2=0, box_height2=0, box_width2=0;
    	int start_row3=0, start_column3=0, box_height3=0, box_width3=0;
    	int start_row4=0, start_column4=0, box_height4=0, box_width4=0;
    	get_bounding_box(height, width1, part1, &start_row1, &start_column1, &box_height1, &box_width1);
    	get_bounding_box(height, width2, part2, &start_row2, &start_column2, &box_height2, &box_width2);
    	get_bounding_box(height, width3, part3, &start_row3, &start_column3, &box_height3, &box_width3);
    	get_bounding_box(height, width4, part4, &start_row4, &start_column4, &box_height4, &box_width4);
    	int box1[box_height1][box_width1];
    	int box2[box_height2][box_width2];
    	int box3[box_height3][box_width3];
    	int box4[box_height4][box_width4];
    	
    	copy_pixels(height, width1, part1, start_row1, start_column1, box_height1, box_width1, box1);
    	copy_pixels(height, width2, part2, start_row2, start_column2, box_height2, box_width2, box2);
    	copy_pixels(height, width3, part3, start_row3, start_column3, box_height3, box_width3, box3);
    	copy_pixels(height, width4, part4, start_row4, start_column4, box_height4, box_width4, box4);
    	
    	int half_height1=box_height1/2;
        int half_height2=box_height2/2;
        int half_height3=box_height3/2;
        int half_height4=box_height4/2;
        int half_width1=box_width1/2;
    	int half_width2=box_width2/2;
    	int half_width3=box_width3/2;
    	int half_width4=box_width4/2;
    	int half1[half_height1][half_width1];
    	int x=0,y=0;
    	for(x=0;x<half_height1;x++){
    		for(y=0;y<half_width1;y++){
    			half1[x][y]=0;   	
    		}
    	}
    	int half2[half_height2][half_width2];
    	
    	for(x=0;x<half_height2;x++){
    		for(y=0;y<half_width2;y++){
    			half2[x][y]=0;   	
    		}
    	}
    	int half3[half_height3][half_width3];
    	
    	for(x=0;x<half_height3;x++){
    		for(y=0;y<half_width3;y++){
    			half3[x][y]=0;   	
    		}
    	}
    	int half4[half_height4][half_width4];
    	
    	for(x=0;x<half_height4;x++){
    		for(y=0;y<half_width4;y++){
    			half4[x][y]=0;   	
    		}
    	}
    	//Now half the image;
    	       
        half_image(box_height1,box_width1,half_height1,half_width1,box1,half1);//half the size of the box
        half_image(box_height2,box_width2,half_height2,half_width2,box2,half2);
        half_image(box_height3,box_width3,half_height3,half_width3,box3,half3);
        half_image(box_height4,box_width4,half_height4,half_width4,box4,half4);
        
        int up_height1=half_height1*half_width1;//make it a square
        int up_height2=half_height2*half_width2;
        int up_height3=half_height3*half_width3;
        int up_height4=half_height4*half_width4;
        
        int up_array1[up_height1][up_height1];
        int up_array2[up_height2][up_height2];
        int up_array3[up_height3][up_height3];
        int up_array4[up_height4][up_height4];
        
        
        make_square(half_height1,half_width1,up_height1,half1,up_array1);//make the halfed size box a large square
        make_square(half_height2,half_width2,up_height2,half2,up_array2);
        make_square(half_height3,half_width3,up_height3,half3,up_array3);
        make_square(half_height4,half_width4,up_height4,half4,up_array4);
        
        int down_square1[side][side] = {{0}}; 
        int down_square2[side][side] = {{0}};
        int down_square3[side][side] = {{0}};
        int down_square4[side][side] = {{0}};      
       	
        
       
        scale_down_square(side,up_height1,up_array1,down_square1);
        scale_down_square(side,up_height2,up_array2,down_square2);
        scale_down_square(side,up_height3,up_array3,down_square3);
        scale_down_square(side,up_height4,up_array4,down_square4);
        
        
        
  		//Here we change the two dimensional array of back_up to a one dimensional array inputs 
  		double inputs1[in]={0.0};//input pixels, black pixels represent 1, white pixels represent 0
  		double inputs2[in]={0.0};
  		double inputs3[in]={0.0};
  		double inputs4[in]={0.0};
  		
  		       
        int k=0;
        while(k<in){
          for(i=0;i<side;i++){
            for(j=0;j<side;j++){
			  //inputs[k]=down_square[i][j];
			  if(down_square1[i][j]==1){
			  	inputs1[k]=1.0;
			  }
			  else{
			  	inputs1[k]=-1.0;
			  }            
              k++;
            }
          }
        }k=0;
        while(k<in){
          for(i=0;i<side;i++){
            for(j=0;j<side;j++){
			  //inputs[k]=down_square[i][j];
			  if(down_square2[i][j]==1){
			  	inputs2[k]=1.0;
			  }
			  else{
			  	inputs2[k]=-1.0;
			  }            
              k++;
            }
          }
        }k=0;
        while(k<in){
          for(i=0;i<side;i++){
            for(j=0;j<side;j++){
			  //inputs[k]=down_square[i][j];
			  if(down_square3[i][j]==1){
			  	inputs3[k]=1.0;
			  }
			  else{
			  	inputs3[k]=-1.0;
			  }            
              k++;
            }
          }
        }k=0;
        while(k<in){
          for(i=0;i<side;i++){
            for(j=0;j<side;j++){
			  //inputs[k]=down_square[i][j];
			  if(down_square4[i][j]==1){
			  	inputs4[k]=1.0;
			  }
			  else{
			  	inputs4[k]=-1.0;
			  }            
              k++;
            }
          }
        }k=0;
        

        double output1_1[neuron]={0.0};//after weight1*input
        double output1_2[neuron]={0.0};
        double output1_3[neuron]={0.0};
        double output1_4[neuron]={0.0};
        
        
        double output2_1[out]={0.0};//after weight2*activated1    
        double output2_2[out]={0.0}; 
        double output2_3[out]={0.0}; 
        double output2_4[out]={0.0}; 
         
                 
        double activated1_1[neuron]={0.0};// sigmoid(output1)
        double activated1_2[neuron]={0.0};
        double activated1_3[neuron]={0.0};
        double activated1_4[neuron]={0.0};
        
        
        double activated2_1[out]={0.0};// sigmoid(output2)  sigmoid: 1/(1+exp(-x))
        double activated2_2[out]={0.0};
        double activated2_3[out]={0.0};
        double activated2_4[out]={0.0};
       
       
        dot_product_layer1(in,neuron,inputs1, weight1_1, output1_1);
    	dot_product_layer1(in,neuron,inputs2, weight1_2, output1_2);
    	dot_product_layer1(in,neuron,inputs3, weight1_3, output1_3);
    	dot_product_layer1(in,neuron,inputs4, weight1_4, output1_4);
    	
    	
        sigmoid1(neuron,output1_1, activated1_1);
        sigmoid1(neuron,output1_2, activated1_2);
        sigmoid1(neuron,output1_3, activated1_3);
        sigmoid1(neuron,output1_4, activated1_4);
        
        
        dot_product_layer2(out,neuron,output2_1, weight2_1, activated1_1);
        dot_product_layer2(out,neuron,output2_2, weight2_2, activated1_2);
        dot_product_layer2(out,neuron,output2_3, weight2_3, activated1_3);
        dot_product_layer2(out,neuron,output2_4, weight2_4, activated1_4);
        
        
        sigmoid2(out,output2_1, activated2_1);
        sigmoid2(out,output2_2, activated2_2);
        sigmoid2(out,output2_3, activated2_3);
        sigmoid2(out,output2_4, activated2_4);
        
               
        


        //Get digit
    int digit1=0;
    int digit2=0;
    int digit3=0;
    int digit4=0;
    double greatest=0.0;//to find out which digit has the highest probability
        for(i=0;i<out;i++){
            if(activated2_1[i]>greatest){
                greatest=activated2_1[i];
                digit1=i;
            }
        }
        greatest=0.0;
        
        for(i=0;i<out;i++){
            if(activated2_2[i]>greatest){
                greatest=activated2_2[i];
                digit2=i;
            }
        }
        greatest=0.0;
        
        for(i=0;i<out;i++){
            if(activated2_3[i]>greatest){
                greatest=activated2_3[i];
                digit3=i;
            }
        }
        greatest=0.0;
        
        for(i=0;i<out;i++){
            if(activated2_4[i]>greatest){
                greatest=activated2_4[i];
                digit4=i;
            }
        }
        greatest=0.0;
        
        printf("%d%d%d%d\n",digit1,digit2,digit3,digit4);	


    return 0;
}
		

