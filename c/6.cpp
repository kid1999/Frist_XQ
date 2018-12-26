#include<stdio.h>
main()
{
	int a,b,c,d;
	scanf("%d,%d,%d",&a,&b,&c);
	if(a>b)
	a=a;
	else
	a=b;
	if(a>c)
	a=a;
	else
	a=c;

	if(a>b+c)
	printf("no");
	else
	printf("yes");
}
