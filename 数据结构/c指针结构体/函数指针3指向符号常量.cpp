#include<iostream>
#include<string.h> 
using namespace std;

main()
{	int a = 5;
	const int *p;   //ָ����ų�����ָ��  >>��ָ�������ݲ��ܱ��ı� 
	p=&a;
	cout<<*p<<endl; 
	
	//����
	*p=56;
	cout<<*p<<endl; 
 } 
