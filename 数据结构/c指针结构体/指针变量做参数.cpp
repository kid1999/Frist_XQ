#include<stdio.h>
void rank(int *q1,int *q2)
{
	int temp;
	if(*q1<*q2)
	{
		temp=*q1;
		*q1=*q2;
		*q2=temp;
		
	}
 } 
 
main()
{
	int a,b,*p1,*p2;
	scanf("%d%d",&a,&b);
	p1=&a;
	p2=&b;
	rank(p1,p2); 					//����ָ�������������޸�ԭ�����ݵ�ֵ                    
	printf("max:%d...min:%d",a,b);
 } 
