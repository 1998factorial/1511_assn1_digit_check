void copy_pixels(int height, int width, int pixels[height][width],int start_row, int start_column, int copy_height, int copy_width,int copy[copy_height][copy_width]){
         int col=0,row=0,x=0,y=0;
         //start_row<col<start_row+height
         //start_column<row<start_column+width
         //pixels[col][row]
         //copy[x][y]
         //copy_width=box_width
         //copy_height=box_height
         
         for(y=0;y<copy_height;y++){
         	for(x=0;x<copy_width;x++){
         		copy[y][x]=pixels[start_row+y][start_column+x];
         		
         	
		     }        
         }

}
