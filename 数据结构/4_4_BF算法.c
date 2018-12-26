#include<stdio.h>
#include<malloc.h>
#include<string.h>

#include "DString.h"

int BFindex(DString s,int start,DString t){
	int i =start,j = 0,v;
	while(i<s.length && j<t.length){
		if(s.str[i] == t.str[j]){
			i++;
			j++;
		}
		else{
			i = i-j+1;	
			j = 0;
		}
	}
	if(j == t.length) v = i-t.length;	//Æ¥ÅäÆðÊ¼Î»ÖÃ
	else v = -1;
	return v; 
} 

main(){
	DString s1,s2;
	int max1 =20,max2 = 2;
	int pos = 0;
	
	Initate(&s1,max1,"aa bb cc aa bb cc");
	Initate(&s2,max2,"bb");
	
	// find1
	pos = BFindex(s1,pos,s2);
	printf("pos  = %d\n",pos);
	
	// find2
	pos = BFindex(s1,pos+1,s2);
	printf("pos  = %d\n",pos);
	
	Destroy(&s1);
	Destroy(&s2);
}
