#include<stdio.h>
void chopToFour(int height,int width,int pixels[height][width],int *firstStartCol,int *firstFinishCol,int *secondStartCol,int *secondFinishCol,int *thirdStartCol,int *thirdFinishCol,int *lastStartCol,int *lastFinishCol){
	int col=0;
	int row=0;
	int count=0;
	int sum=0;	
	for(col=0;col<width;col++){		
		for(row=0;row<height;row++){			
			sum+=pixels[row][col];	
		}
		//printf("col%d, sum: %d \n",col,sum);
		if(sum!=0){
			*firstStartCol=col;
			  break;			
		}	
	}
	
	for(col=*firstStartCol;col<width;col++){		
		sum=0;
		for(row=0;row<height;row++){			
			sum+=pixels[row][col];		
		}
		if(sum==0){
			*firstFinishCol=col-1;
			  break;			
		}	//first box
	}
	for(col=*firstFinishCol+1;col<width;col++){		
		for(row=0;row<height;row++){			
			sum+=pixels[row][col];	
		}
		//printf("col%d, sum: %d \n",col,sum);
		if(sum!=0){
			*secondStartCol=col;
			  break;			
		}	
	}
	
	for(col=*secondStartCol;col<width;col++){		
		sum=0;
		for(row=0;row<height;row++){			
			sum+=pixels[row][col];		
		}
		if(sum==0){
			*secondFinishCol=col-1;
			  break;			
		}	
	}  // second box
	for(col=*secondFinishCol+1;col<width;col++){		
		for(row=0;row<height;row++){			
			sum+=pixels[row][col];	
		}
		//printf("col%d, sum: %d \n",col,sum);
		if(sum!=0){
			*thirdStartCol=col;
			  break;			
		}	
	}
	
	for(col=*thirdStartCol;col<width;col++){		
		sum=0;
		for(row=0;row<height;row++){			
			sum+=pixels[row][col];		
		}
		if(sum==0){
			*thirdFinishCol=col-1;
			  break;			
		}	
	}//third box
	for(col=*thirdFinishCol+1;col<width;col++){		
		for(row=0;row<height;row++){			
			sum+=pixels[row][col];	
		}
		//printf("col%d, sum: %d \n",col,sum);
		if(sum!=0){
			*lastStartCol=col;
			  break;			
		}	
	}
	
	for(col=*lastStartCol;col<width;col++){		
		sum=0;
		for(row=0;row<height;row++){			
			sum+=pixels[row][col];		
		}
		if(sum==0 || col==width-1){
			*lastFinishCol=col-1;
			  break;			
		}	
	}//last box
	
}
