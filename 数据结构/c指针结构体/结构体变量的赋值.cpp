#include<stdio.h>

	struct student
	{
		int id;
		char name[10];
	};

main()
{
	student one = {123,"hello"};
	student two;		//结构体变量的赋值  》》 copy一份
	two=one ; 
	printf("%d\n%s",two.id,two.name);
 } 
