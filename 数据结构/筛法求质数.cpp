#include<stdio.h>
#include<math.h> 
#include<string.h> 
//求质数   筛法 
main(){
	
	int n =100;	//求的范围
	bool a[101];
	int i,j;
    memset(a, 1, sizeof(a));	//初始化函数	
	a[1] =0;
	for(i=2;i<=sqrt(n);i++){	//开始 
		if(a[i])				//如果已经被筛 跳过 (避免重复) 
		{
			for(j=2;j<=n/i;j++)	//筛 
				a[i*j] = 0; 
		}
	}
	
	for(i=2;i<n;i++){	//输出结果 
		if(a[i])
			printf("%d\n",i); 
	} 
} 
