// 可变参数 
#include<stdio.h>
#include<stdarg.h>
 //num:可变参数的总数   ...可变参数 
double average(int num,...)
{
	va_list valist;
	double sum =0.0;
	int i;
	
	//为num个参数 初始化 valist
	va_start(valist,num);
	
	// 访问所有valist的参数
	for(i =0;i<num;i++)
		sum += va_arg(valist,int);
	
	//清理为valist保留的内存
	va_end(valist); 
	
	return sum/num; 
}

main(){
	printf("first: %f \n",average(4,4,5,6,7));
		printf("second: %f \n",average(3,13,14,15));
	
}

