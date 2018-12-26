#include<stdio.h>
main()
{
	int *p;
	int a;
	a=11;
	p=&a;
	printf("输出地址%x\n",&a);//       p=$a   且输出格式 p 和 x 效果一样 
	printf("输出值  %d  ",*p); // *p= a 
 } 
