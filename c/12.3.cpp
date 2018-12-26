#include<stdio.h>
main()
{
	int a[15],i=1,n;
	    printf("请输入:");
		scanf("%d",&n);
	    a[0]=n;
do
	{
		printf("输入:");
	    scanf("%d",&n);
	
	if(n>a[i-1])
{
	a[i]=n;
	i++;
}
	else
	printf("请重新");
	continue;
}
while(i<15);
	
	for(i=0;i<15;i++)
	printf("%d    ",a[i]);
 } 
