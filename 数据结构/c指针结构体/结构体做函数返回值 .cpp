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
	student make = reone();    // 将结构体做函数返回值 
	printf("%d\n%s",make.id,make.name);
 } 
