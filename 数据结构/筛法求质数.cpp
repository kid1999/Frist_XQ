#include<stdio.h>
#include<math.h> 
#include<string.h> 
//������   ɸ�� 
main(){
	
	int n =100;	//��ķ�Χ
	bool a[101];
	int i,j;
    memset(a, 1, sizeof(a));	//��ʼ������	
	a[1] =0;
	for(i=2;i<=sqrt(n);i++){	//��ʼ 
		if(a[i])				//����Ѿ���ɸ ���� (�����ظ�) 
		{
			for(j=2;j<=n/i;j++)	//ɸ 
				a[i*j] = 0; 
		}
	}
	
	for(i=2;i<n;i++){	//������ 
		if(a[i])
			printf("%d\n",i); 
	} 
} 
