#include<stdio.h>

int a[] = {11,2,2,23,15,12,23,555,121221,1};

//����Ԫ��
void swap(int *b,int *c){
	int t;
	t = *b;
	*b = *c;
	*c = t;
} 

// ����
void quick_sort(int a[],int l,int r)
{
	if(l>=r) return ;
	int i=l,j=r,k = a[l];	//ȡ��һ��Ԫ��Ϊ�ؼ���
	while(i!=j){
		while(i<j && a[j] >= k)
			--j;
		swap(a+i,a+j);
		
		while(i<j && a[i] <=k)
			i++;
		swap(a+i,a+j);
		
	}
	quick_sort(a,l,i-1);		//���ҵݹ����� 
	quick_sort(a,i+1,r);
 } 
 
main(){
	int i=0;
	quick_sort(a,0,9);
	for(i;i<9;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[9]);
} 
