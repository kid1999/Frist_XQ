#include<stdio.h>

//λ��   ������С��ռ�ÿռ� 
struct Age 
{		//���ܴ��� int����ķ�Χ 
	unsigned int age: 1;		//2��1�η���Χ   unsigned ��ʾֻΪ���� 
}; 

main()
{
	struct Age one;
	one.age = 1;
	printf("%d \n",one.age);
 } 
