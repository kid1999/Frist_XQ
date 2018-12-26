#include<iostream>
#include<string.h> 
using namespace std;

void function()
{	int a=0; 
	static int b=0;  //静态局部变量,函数结束后依然存在(在此调用时,不会重新初始化 
	a+=1;
	b+=1;
	cout<<a<<endl;
	cout<<b<<endl;
}

main()
{
	for(int i=0;i<5;i++)
	{
		function();
		cout<<"Call Again"<<endl;
	}
 } 
