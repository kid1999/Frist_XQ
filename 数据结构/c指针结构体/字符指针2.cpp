#include<iostream>
using namespace std;

main()
{
	char buffer[]= "how are you!";
	char *p;
	p="hello"; //ֱ�ӽ��ַ�����ַ����ָ�� 
	cout<<p<<endl;
	p++;
	cout<<p<<endl;  //���� ��p��ͷ���ַ��� 
	cout<<*p<<endl;  //��һ��,���������ַ� 
	
	p=buffer;    //ָ������ָ�� 
	cout<<p<<endl;
}
