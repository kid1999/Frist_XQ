#include<stdio.h>
main()
	{
		int max(int,int);
		int (*p)(int,int);
		int a,b,c;
		p=max;
		scanf("%d,%d",&a,&b);
		c=(*p)(a,b);
		printf("a=%d\nb=%d\nmax=%d\n",a,b,c);
		
	}
		int max(int x,int y)
	{
		int z;
		if(x>y)
		z =x;
		else
		z=y;
		return (z);
	}

