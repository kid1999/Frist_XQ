#include<stdio.h>
main()
{
	int a[15],i=1,n;
	    printf("������:");
		scanf("%d",&n);
	    a[0]=n;
do
	{
		printf("����:");
	    scanf("%d",&n);
	
	if(n>a[i-1])
{
	a[i]=n;
	i++;
}
	else
	printf("������");
	continue;
}
while(i<15);
	
	for(i=0;i<15;i++)
	printf("%d    ",a[i]);
 } 
