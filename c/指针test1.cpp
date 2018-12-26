#include<stdio.h>
main()
{
	int i ,n;
	int a[2][2]={{1,2},{3,4}};
	for(i=0;i<2;i++)
	for(n=0;n<2;n++)
	printf(" %d",a[i][n]);
	printf("\n");
	printf("输出验证:\n");
	
	
	printf("%d\n",a);  // 0行首字母 
	printf("%d  %d  %d\n",a[0],*a,*(a+0));  // 0行0列元素 
	printf("%d\n",a+1);  //  1行首字母 
	printf("%d  %d  %d\n",a[1],&a[1][0],*(a+1));  //1行0列元素 
	printf("%d  %d\n",*(*(a+1)+1),*(a+1)+1);   //1行1列元素的值与地址
	printf("%d  %d\n",a[0][0],*(*a)); //0 0 的值
	printf("%d  %d\n",*a[1],a[1][0]);  // 1 0 dehi 
}

