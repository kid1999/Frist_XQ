#include<stdio.h>

//位域   尽可能小的占用空间 
struct Age 
{		//不能大于 int定义的范围 
	unsigned int age: 1;		//2的1次方范围   unsigned 表示只为正数 
}; 

main()
{
	struct Age one;
	one.age = 1;
	printf("%d \n",one.age);
 } 
