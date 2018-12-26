#include<stdio.h>
#include<string> 
using namespace std;

int BF(string s1,string s2,int pos)
{
	int i = pos-1;
	int j=0;
	
	while(i<s1.length() && j<s2.length())  //进行匹配 
	{
		if(s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else{
			i = i-j+2;
			j = 0;
		}
	}
	if(j>=s2.length())		//找到了匹配	
		return i-s2.length();
	return 0;
}

main(){
	string s1 = "abcdadasdsaxbcdefg";
	string s2 = "abcde";
	int pos = 1;	//从第二个元素开始匹配
	printf("%d",BF(s1,s2,pos));
} 
