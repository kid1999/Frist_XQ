#include<stdio.h>
main()
{
	int a[10],i,s,n;
	for(i=0;i<10;i++)
	{printf("����n��");
	scanf("%d",&a[i]);
	}
	
	for(i=0,n=9;i<5;i++,n--) //ע����ֹ���� 
	{
		s=a[i];
		a[i]=a[n];
		a[n]=s;
	}
	for(i=0;i<10;i++)
	printf("%d  ",a[i]);
	
	
}
