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
	printf("��λ��\n");
	else if (n<100&&n>9)
{
		printf("Sλ��\n");
	n=g*10+s; }
	else if(n<1000&&n>99)
	{
	printf("Bλ��\n");
	n=g*100+s*10+b;
}
	else
{
		printf("Qλ��\n");
		n=g*1000+s*100+b*10+q;}
	
		printf("%d",n);
	
	
	
} 
