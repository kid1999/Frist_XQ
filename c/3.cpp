#include<stdio.h>
main()
{
	int v,t;
	float s;
	scanf("%d,%d",&v,&t);
	s=0.5*9.81*t*t+v*t;
	printf("%.2f",s);
	
 } 
