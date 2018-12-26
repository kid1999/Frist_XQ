#include<stdio.h>
main()
{
	int i=1;
	float n=200;
	do{
		n=1.015*n;
		i++;
		
	}
	while(n<1000);
	printf("ำรมห%d",i);
	
 } 
