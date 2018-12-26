#include<iostream>
using namespace std;

main()
{
	char a[]= "how are you!", b[20];
	char *p1,*p2;
	for (p1=a,p2=b;*p1!='\0';p1++,p2++)
		*p2=*p1;
	*p2='\0';
	
	cout<<a<<endl;
	cout<<b<<endl ;
}
