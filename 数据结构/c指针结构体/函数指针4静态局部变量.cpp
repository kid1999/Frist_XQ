#include<iostream>
#include<string.h> 
using namespace std;

void function()
{	int a=0; 
	static int b=0;  //��̬�ֲ�����,������������Ȼ����(�ڴ˵���ʱ,�������³�ʼ�� 
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
