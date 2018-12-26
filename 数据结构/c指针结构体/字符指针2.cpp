#include<iostream>
using namespace std;

main()
{
	char buffer[]= "how are you!";
	char *p;
	p="hello"; //直接将字符串地址赋给指针 
	cout<<p<<endl;
	p++;
	cout<<p<<endl;  //代表 以p开头的字符串 
	cout<<*p<<endl;  //降一级,代表具体的字符 
	
	p=buffer;    //指针重新指向 
	cout<<p<<endl;
}
