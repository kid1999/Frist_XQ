#include<stdio.h>
main()
{
	int i=1;
	float h=600,s=600;  //ע����� ����Ҫ�� 
	do
	{
		h=0.5*h;
	    s=s+2*h;
		i++;
	}
	while(i<16);
   printf("�߶�:%f\n ·��:%f",h,s);
	
 } 
