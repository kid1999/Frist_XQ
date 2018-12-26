#include<stdio.h>

	struct student
	{
		int id;
		char name[10];
	};

main()
{
	student one = {123,"hello"};
	student *p= &one;		//用指针指向结构体
	printf("%d\n%s",p->id,p->name);
 } 
