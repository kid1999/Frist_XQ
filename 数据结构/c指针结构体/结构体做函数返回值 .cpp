#include<stdio.h>

	struct student
	{
		int id;
		char name[10];
	};

student reone()
{
	student one = {123,"hello"};
	return one;
 } 
main()
{
	student make = reone();    // ���ṹ������������ֵ 
	printf("%d\n%s",make.id,make.name);
 } 
