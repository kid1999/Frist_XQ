#include<stdio.h>
#include<string.h> 

//�����嶨��
union Data
{
	int i;
	float f;
	char str[20]; 
};

main()
{
	union Data data;

//��ʼ��	
   data.i = 10;
   data.f = 220.5;
   strcpy( data.str, "C Programming");
 
 
 //ͬһʱ��ֻ�õ�һ����Ա				�˴����� !!! 
   printf( "data.i : %d\n", data.i);
   printf( "data.f : %f\n", data.f);
   printf( "data.str : %s\n", data.str);
 
	printf("%d \n",sizeof(data));		//��������ռ�ռ�Ϊ�������Ŀռ� 
}
