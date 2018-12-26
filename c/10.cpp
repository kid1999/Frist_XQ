#include<stdio.h>
main()
{
	int i=1;
	float h=600,s=600;  //注意变量 精度要求 
	do
	{
		h=0.5*h;
	    s=s+2*h;
		i++;
	}
	while(i<16);
   printf("高度:%f\n 路程:%f",h,s);
	
 } 
