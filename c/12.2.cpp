#include<stdio.h>
main()
{
	int i=0,x,y;
	int a[4][4]={{2,5,6,9},{8,7,9,6},{8,1,0,3},{4,5,7,0}};
	for(x=0;x<4;x++)
	{
		y=3-x;
	i=i+a[x][x]+a[x][y];
}
printf("½á¹ûÊÇ %d",i);
 } 
