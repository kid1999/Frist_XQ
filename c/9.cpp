#include<stdio.h>
main()
{
	int x,y=0,i,n,p,jg=0;
	printf("����������: ");
	scanf("%d,",&n);
	for(i=1;i<=n;i++)
	{
	printf("����ɼ�:  ");
	scanf("%d",&x);
		y=y+x;
		
	if(x>=60)
	jg=jg+1;
	

}
    p=y/n;
    printf("������:%d\n �ܳɼ�:%d\n ƽ����:%d\n ��������:%d\n ",n,y,p,jg);
 } 
