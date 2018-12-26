#include<stdio.h>
main()
{
	int a[5]={1,2,3,4,5};
	int i;
	int *p= a;
	for(i=0;i<5;i++)
{
		//printf("输出第%d个数组的地址 %x  值 %d\n",i+1,&a[i],a[i]);        //  a[i]=p[i]  的值 任意交换无影响 
        //printf("输出第%d个数组的地址 %x  值 %d\n",i+1,p+i,*(p+i)); 
			printf("输出第%d个数组的地址 %x  值 %d\n",i+1,p++,*p);
			
			printf("         \n");

}    
printf("重新进行\n");
p=a;
	for(i=0;i<5;i++)
	printf("输出第%d个数组的地址 %x  值 %d\n",i+1,p++,*p);
 } 
