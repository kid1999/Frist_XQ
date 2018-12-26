#include<iostream>
#include<string.h> 
using namespace std;

main()
{	int a = 5;
	const int *p;   //指向符号常量的指针  >>被指定的数据不能被改变 
	p=&a;
	cout<<*p<<endl; 
	
	//错误
	*p=56;
	cout<<*p<<endl; 
 } 
