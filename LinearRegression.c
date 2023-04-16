
#include<stdio.h>
#include<stdlib.h>

//declaring a fuinction
void calculate();

//main function
void main(){
	
	//Welcome GUI
	printf("**************************************************************************************************");
	printf("\n\n\n");
	printf("Welcome to Linear Regression Application");
	printf("\n\n\n");
	printf("**************************************************************************************************\n\n\n");
	
	//calling function
	calculate();
	
	//Ending gui
	printf("\n\n\n");
	printf("**************************************************************************************************");
	printf("\n\n\n");
	printf("Thank you for using Linear Regression Application");
	printf("\n\n\n");
	printf("**************************************************************************************************\n\n\n");
}


//all the calculation part is done in this fucntion.
void calculate(){
	//initalizing file pointers
	FILE *f1,*f2,*f3,*f4;
	//initializing variable
	float a,b,x_axs, result;
	float x, y, sum_x, sum_y, sum_xx, sum_yy, sum_xy;
	
	int n=0;

	//reading files, if not found exit the program
	f1 = fopen("datasetLR1.txt","r");  
	if(f1 == NULL){
		printf("Unable to find the file");
		exit(0);
	}
	f2 = fopen("datasetLR2.txt","r");
	if(f2 == NULL){
		printf("Unable to find the file");
		exit(0);
	}
	f3 = fopen("datasetLR3.txt","r");
	if(f3 == NULL){
		printf("Unable to find the file");
		exit(0);
	}
	f4 = fopen("datasetLR4.txt","r");
	if(f4 == NULL){
		printf("Unable to find the file");
		exit(0);
	}
	
	// calcuating the necessary values to find a & b from the 4 files
	// Also EOF is the end of the file 
	while(fscanf(f1,"%f,%f",&x,&y) != EOF){
		sum_x = sum_x + x;
		sum_y = sum_y + y;
		sum_xy = sum_xy + (x*y);
		sum_xx = sum_xx + (x*x);
		sum_yy = sum_yy + (y*y);
		n+=1;
	}
	fclose(f1);
	
	while(fscanf(f2,"%f,%f",&x,&y) != EOF){
		sum_x = sum_x + x;
		sum_y = sum_y+ y;
		sum_xy = sum_xy + (x*y);
		sum_xx = sum_xx + (x*x);
		sum_yy = sum_yy + (y*y);
		n+=1;
	}
	fclose(f2);
	
	while(fscanf(f3,"%f,%f",&x,&y) != EOF){
		sum_x = sum_x + x;
		sum_y = sum_y + y;
		sum_xy = sum_xy + (x*y);
		sum_xx = sum_xx + (x*x);
		sum_yy = sum_yy + (y*y);
		n+=1;
	}
	fclose(f3);
	
	while(fscanf(f4,"%f,%f",&x,&y) != EOF){
		sum_x = sum_x + x;
		sum_y = sum_y+ y;
		sum_xy = sum_xy + (x*y);
		sum_xx = sum_xx + (x*x);
		sum_yy = sum_yy + (y*y);
		n+=1;
	}
	fclose(f4);
	
	
	//calculating the values of a & b  and printing it.
	a = ((sum_y * sum_xx) - (sum_x * sum_xy)) / ((n * sum_xx) - ((sum_x) * (sum_x)));
	b = ((n * sum_xy) - ((sum_x) * (sum_y))) / ((n * sum_xx) - ((sum_x) * (sum_x)));	
	printf("The values of A and B after calculation from the given files are: \n\na = %f, b = %f\n\n",a,b);
	
	
	//Regression equation:- y = bx+a..
	printf("The regression line equation is: ");
	printf("y = %.3f*x + %.3f\n\n",b,a);
	
	
	//user input x into the equation
	printf("Enter the value for x: ");
	scanf("%f",&x_axs);
	result = b * x_axs + a;
	printf("\nThe value of y from equation= %.3f",result);
	
}



