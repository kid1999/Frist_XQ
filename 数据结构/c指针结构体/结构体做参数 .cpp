#include<stdio.h>
#include<string.h>
	struct student
	{
		int id;
		char name[10];
	};
void renew(student one)			//�ṹ�������� 
{
	one.id = 20180000 + one.id;
	strcpy(one.name,"newname");			//�ַ����ĸ��� 
	printf("%d:%s\n",one.id,one.name); 
}

main()
{
	student one = {123,"hello"};
	renew(one);							//���ú���  >> ��one ��ֵ copy�� ջ 
	printf("%d:%s",one.id,one.name);
 } 
