#include<stdio.h>
main()
{
	int a[5]={1,2,3,4,5};
	int i;
	int *p= a;
	for(i=0;i<5;i++)
{
		//printf("�����%d������ĵ�ַ %x  ֵ %d\n",i+1,&a[i],a[i]);        //  a[i]=p[i]  ��ֵ ���⽻����Ӱ�� 
        //printf("�����%d������ĵ�ַ %x  ֵ %d\n",i+1,p+i,*(p+i)); 
			printf("�����%d������ĵ�ַ %x  ֵ %d\n",i+1,p++,*p);
			
			printf("         \n");

}    
printf("���½���\n");
p=a;
	for(i=0;i<5;i++)
	printf("�����%d������ĵ�ַ %x  ֵ %d\n",i+1,p++,*p);
 } 
