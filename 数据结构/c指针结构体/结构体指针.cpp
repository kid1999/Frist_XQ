#include<stdio.h>

	struct student
	{
		int id;
		char name[10];
	};

main()
{
	student one = {123,"hello"};
	student *p= &one;		//��ָ��ָ��ṹ��
	printf("%d\n%s",p->id,p->name);
 } 
