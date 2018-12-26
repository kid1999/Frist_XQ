#include<stdio.h>
#include<string.h>
	struct student
	{
		int id;
		char name[10];
	};
void renew(student one)			//结构体做参数 
{
	one.id = 20180000 + one.id;
	strcpy(one.name,"newname");			//字符串的复制 
	printf("%d:%s\n",one.id,one.name); 
}

main()
{
	student one = {123,"hello"};
	renew(one);							//调用函数  >> 将one 的值 copy给 栈 
	printf("%d:%s",one.id,one.name);
 } 
