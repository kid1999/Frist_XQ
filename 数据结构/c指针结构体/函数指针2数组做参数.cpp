#include<iostream>
#include<string.h> 
using namespace std;
int sum(int array[])		//��������������ָ�� 
{	
	for(int i=0;i<5;i++)
	{
		*(array+1) = *array + *(array+1);
		array++;
	 } 
	 return *array;
}
main()
{
	int a[] ={1,2,3,4,5}; 

	cout<<sum(a)<<endl; 
 } 
