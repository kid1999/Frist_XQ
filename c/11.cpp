#include<stdio.h>
main()
{
	int x,y,z,i;
	for(x=0;x<20;x++)
	for(y=0;y<33;y++)
	for(z=0;z<100;z=z+3)
	if(x+y+z==100&&5*x+3*y+(1.0/3)*z==100)   //注意除法运算格式 
	printf("公鸡 %d  母鸡 %d  小鸡 %d\n",x,y,z);
	
 } 
