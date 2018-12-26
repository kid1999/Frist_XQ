#include<stdio.h>
#include<malloc.h>

main(){
	int *a,n=10,i;
	
	// 动态申请 n个int 内存空间 a 指向首地址
	a = (int *)calloc(n,sizeof(int));
	for (i=0;i<n;i++)
		a[i] = i+1;		//赋值
	
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
		
	free(a);	//释放指针 
} 
