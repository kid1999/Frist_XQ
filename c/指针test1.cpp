#include<stdio.h>
main()
{
	int i ,n;
	int a[2][2]={{1,2},{3,4}};
	for(i=0;i<2;i++)
	for(n=0;n<2;n++)
	printf(" %d",a[i][n]);
	printf("\n");
	printf("�����֤:\n");
	
	
	printf("%d\n",a);  // 0������ĸ 
	printf("%d  %d  %d\n",a[0],*a,*(a+0));  // 0��0��Ԫ�� 
	printf("%d\n",a+1);  //  1������ĸ 
	printf("%d  %d  %d\n",a[1],&a[1][0],*(a+1));  //1��0��Ԫ�� 
	printf("%d  %d\n",*(*(a+1)+1),*(a+1)+1);   //1��1��Ԫ�ص�ֵ���ַ
	printf("%d  %d\n",a[0][0],*(*a)); //0 0 ��ֵ
	printf("%d  %d\n",*a[1],a[1][0]);  // 1 0 dehi 
}

