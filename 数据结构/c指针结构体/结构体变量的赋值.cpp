#include<stdio.h>

	struct student
	{
		int id;
		char name[10];
	};

main()
{
	student one = {123,"hello"};
	student two;		//�ṹ������ĸ�ֵ  ���� copyһ��
	two=one ; 
	printf("%d\n%s",two.id,two.name);
 } 
