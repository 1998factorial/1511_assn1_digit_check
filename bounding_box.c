// find minimum rectangle containing all black pixels in image
// Here i am using the lab07 solution  my original function is down below it.
void get_bounding_box(int height, int width, int pixels[height][width], int *start_row, int *start_column, int *box_height, int *box_width) {
    int min_row = height - 1;
    int max_row = 0;
    int min_column = width - 1;
    int max_column = 0;
    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {
            if (pixels[row][column] == 1) {
                if (row < min_row) {
                    min_row = row;
                }
                if (row > max_row) {
                    max_row = row;
                }
                if (column < min_column) {
                    min_column = column;
                }
                if (column > max_column) {
                    max_column = column;
                }
            }
        }
    }
    if (min_row <= max_row) {
        *start_row = min_row;
        *box_height = max_row -  min_row + 1;
        *start_column = min_column;
        *box_width = max_column -  min_column + 1;
    } else {
        // no black pixels in image
        *start_row = 0;
        *box_height = 0;
        *start_column = 0;
        *box_width = 0;
    }
}



/*
void get_bounding_box(int height, int width, int pixels[height][width],int *start_row, int *start_column, int *box_height, int *box_width){

		int col=0,row=0,maxcol=0,maxrow=0,k=0,sum=0,sum1=0,j=0;
			for(col=height-1;col>=0;col--){
				for(row=0;row<width;row++){
					if((pixels[col][row]==1)&&(col!=0)&&(row!=0)){
						for(k=0;k<width;k++){
						sum=sum+pixels[col+1][k];
						sum1=sum1+pixels[col-1][k];						
						}
						if(sum==0){
						maxcol=col;
						}
						if(sum1==0){
						*start_row=col;
						
						}
						sum1=0;sum=0;
						for(j=0;j<height;j++){
						sum=sum+pixels[j][row-1];
						if(row!=width-1){sum1=sum1+pixels[j][row+1];						
						}}
						if(sum==0){
						*start_column=row;
						}
						if(sum1==0){
						maxrow=row;
						
						}
						sum1=0;sum=0;
					}
					
				}
							
			}
		*box_height=maxcol+1-*start_row;
		*box_width=maxrow+1-*start_column;
		
}*/
