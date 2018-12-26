#include<stdio.h>

main()
{
	int a []={1,2,3,4,5};
	int *p;
	p=a;
	printf("%x\n",p);
	printf("%x\n",a);
	
	printf("%d\n",a[0]);
	printf("%d\n",*p);
	printf("%d\n",a[3]);
	printf("%d\n",*p+3);
 } 
