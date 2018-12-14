#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE*f2;
	int i,j;
	double w[10][65];
	f2 = fopen("weights2.txt","r");
	for(i=0;i<10;i++){
	 for(j=0;j<65;j++){
	//fscanf(f2,"%.16g",&w[i][j]); cant use fscanf because the floats are too long and we want the weights to be as presice as possible
	char ch_num[30];
	fgets(ch_num,30,f2);
	w[i][j]=atof(ch_num);
	
	
	printf("weight %d to %d %.16g\n",i,j,w[i][j]);
}
}
	fclose(f2);
}
