#include<stdio.h>
main()
{
	int n,g,s,b,q;
	scanf("%d",&n);
	
	q=n/1000;
	b=(n%1000)/100;
	s=(n%100)/10;
	g=n%10;
	
	if(n<10)
	printf("个位数\n");
	else if (n<100&&n>9)
{
		printf("S位数\n");
	n=g*10+s; }
	else if(n<1000&&n>99)
	{
	printf("B位数\n");
	n=g*100+s*10+b;
}
	else
{
		printf("Q位数\n");
		n=g*1000+s*100+b*10+q;}
	
		printf("%d",n);
	
	
	
} 
