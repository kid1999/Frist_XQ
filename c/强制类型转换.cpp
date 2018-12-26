#include<stdio.h>

main()
{	
	int sum = 17 ,count = 5;
	double mean;
	printf("mean: %f\n",(double)sum/count);		//强制类型转换
	
	char c = 'c';
	printf("sum: %d\n",sum+c); 	//整数提升
	
	 
//	如果一个运算符两边的运算数类型不同，先要将其转换为相同的类型，
//即较低类型转换为较高类型，然后再参加运算
	 
 } 
