#include<stdio.h>

main()
{
	int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int *p;
	p=a[0];
	printf("%x\n",p);             //Ԫ�ؼ� 
	printf("%x\n",&a[0][0]);
		printf("%x\n",p+1);
		printf("%x\n",&a[0][0]+1);
		
	printf("%x\n",a);    		//�м� 
	printf("%x\n",&a[0]);
	printf("%x\n",*&a); 
		printf("%d\n",*a[1]);
		printf("%d\n",*a+1);
//		printf("%d\n",);
		printf("%x\n",a+1);
		printf("%x\n",&a[0]+1);	
		printf("%x\n",*&a+1);

	printf("%x\n",&a);			//���鼶 
	printf("%x\n",&a+1);
	
	} 
