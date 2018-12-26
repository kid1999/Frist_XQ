#include<stdio.h>

main()
{
	int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int *p;
	p=a[0];
	printf("%x\n",p);             //元素级 
	printf("%x\n",&a[0][0]);
		printf("%x\n",p+1);
		printf("%x\n",&a[0][0]+1);
		
	printf("%x\n",a);    		//行级 
	printf("%x\n",&a[0]);
	printf("%x\n",*&a); 
		printf("%d\n",*a[1]);
		printf("%d\n",*a+1);
//		printf("%d\n",);
		printf("%x\n",a+1);
		printf("%x\n",&a[0]+1);	
		printf("%x\n",*&a+1);

	printf("%x\n",&a);			//数组级 
	printf("%x\n",&a+1);
	
	} 
