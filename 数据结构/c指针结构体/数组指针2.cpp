#include<stdio.h>

main()
{
	int a [5]={1,2,3,4,5};
	int *p;
	p=a;
	printf("%x\n",p);
	printf("%x\n",a);	
	printf("%x\n",&a[0]);
	
	printf("%x\n",&a[1]);
	printf("%x\n",&a[0]+1);
	
	printf("%x\n",&a[0]+2); 
	
	printf("%x\n",&a);   //&提权，整个数组的地址 
	printf("%x\n",&a+1); 

 } 
