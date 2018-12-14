

int read_pbm(char filename[], int height, int width, int pixels[height][width]);

int get_pbm_dimensions(char filename[], int *height, int *width);

void print_box(int height, int width, int pixels[height][width]);

void get_bounding_box(int height, int width, int pixels[height][width],
                  int *start_row, int *start_column, int *box_height, int *box_width);
                  
void copy_pixels(int height, int width, int pixels[height][width],
                 int start_row, int start_column, int copy_height, int copy_width,
                 int copy[copy_height][copy_width]);
                 
void half_image(int box_height,int box_width,int half_height,int half_width,int box_pixels[box_height][box_width],int half[half_height][half_width]);//halfing the image

//void split_four(int height, int width, int pixels[height][width],int *x1,int *x2,int *x3);

void make_square(int half_height,int half_width,int up_height,int half[half_height][half_width],int up_array[up_height][up_height]);//scale up the image to a large square
void scale_down_square(int side, int up_height,int up_array[up_height][up_height],int down_square[side][side]);


void make_filename(int num, int ver, char filename[15]);

void ini_network(int neuron ,int out ,int in, double weight1[neuron][in],double weight2[out][neuron],double d_weight1[neuron][in],double d_weight2[out][neuron]);

void dot_product_layer1(int in , int neuron, double inputs[in], double weight1[neuron][in], double output1[neuron] );

void sigmoid1(int neuron, double output1[neuron],double activated1[neuron]);

void dot_product_layer2(int out, int neuron,double output2[out],double weight2[out][neuron],double activated1[out] );

void sigmoid2(int out,double output2[out], double activated2[out]);

void cost_function(int out,int desired_output[out], double activated2[out],double cost[out]);

void update_weights( int neuron, int in, int out,double d_weight1[neuron][in], double d_weight2[out][neuron], double weight1[neuron][in], double weight2[out][neuron],double activated1[neuron],double activated2[out], int desired_output[out], double inputs[in]);

void make_filename(int num, int ver, char filename[20]);//for printing file names on command lines automatically

void chopToFour(int height,int width,int pixels[height][width],int *firstStartCol,int *firstFinishCol,int *secondStartCol,int *secondFinishCol,int *thirdStartCol,int *thirdFinishCol,int *lastStartCol,int *lastFinishCol);














