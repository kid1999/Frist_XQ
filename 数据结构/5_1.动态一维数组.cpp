#include<stdio.h>
#include<malloc.h>

main(){
	int *a,n=10,i;
	
	// ��̬���� n��int �ڴ�ռ� a ָ���׵�ַ
	a = (int *)calloc(n,sizeof(int));
	for (i=0;i<n;i++)
		a[i] = i+1;		//��ֵ
	
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
		
	free(a);	//�ͷ�ָ�� 
} 
