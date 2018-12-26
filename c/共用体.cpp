#include<stdio.h>
#include<string.h> 

//共用体定义
union Data
{
	int i;
	float f;
	char str[20]; 
};

main()
{
	union Data data;

//初始化	
   data.i = 10;
   data.f = 220.5;
   strcpy( data.str, "C Programming");
 
 
 //同一时间只用到一个成员				此处报错 !!! 
   printf( "data.i : %d\n", data.i);
   printf( "data.f : %f\n", data.f);
   printf( "data.str : %s\n", data.str);
 
	printf("%d \n",sizeof(data));		//共用体所占空间为最大变量的空间 
}
