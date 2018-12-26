#include<stdio.h>
main()
{
	int x,y=0,i,n,p,jg=0;
	printf("输入总人数: ");
	scanf("%d,",&n);
	for(i=1;i<=n;i++)
	{
	printf("输入成绩:  ");
	scanf("%d",&x);
		y=y+x;
		
	if(x>=60)
	jg=jg+1;
	

}
    p=y/n;
    printf("总人数:%d\n 总成绩:%d\n 平均分:%d\n 及格人数:%d\n ",n,y,p,jg);
 } 
