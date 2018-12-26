#include<iostream>
using namespace std;
void change(int *p,int b)
{
	*p=*p*3;
	b=b*3;
}
main()
{
	int a =10;
	int b =20;
	int *p;
	p=&a;
	
	change(p,b);
	cout<<*p<<endl;
	cout<<b<<endl; 
 } 
