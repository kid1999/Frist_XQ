#include<stdio.h>
main()
{
	int *p;
	int a;
	a=11;
	p=&a;
	printf("�����ַ%x\n",&a);//       p=$a   �������ʽ p �� x Ч��һ�� 
	printf("���ֵ  %d  ",*p); // *p= a 
 } 
