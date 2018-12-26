#include<stdio.h>
#include<malloc.h>
#include<string.h>

#include "DString.h"
void GetNext(DString t,int next[]){
	int j = 1,k = 0;
	next[0] = -1;
	next[1] = 0;
	
	while(j<t.length -1){
		if(t.str[j] == t.str[k]){		//匹配上 
			next[j+1] = k+1;
			j++;
			k++;
		}
		else if(k == 0){			//没配上 
			next[j+1] = 0;
			j++;
		} 
		else k = next[k];		//匹配上一段 后失败 
	}
}

int KMPIndex(DString s,int start,DString t,int next[]){
	int i = start,j =0,v;
	while(i<s.length && j<t.length){
		if(s.str[i] == t.str[j]){
			i++;
			j++;
		}
		else if(j==0) i++;
		else j = next[j];
	}
	if(j == t.length)  v = i-t.length;
	else v = -1;
	return v;
} 

//
main(){
	DString s1,s2;
	int max1 =20, max2 =5;
	int pos = 0;
	int next[max2];
	
		
	Initate(&s1,max1,"abcdeacdeacd");
	Initate(&s2,max2,"acd");
	
//	printf("%s  %d\n",s1.str,strlen(s1.str)); 
//	printf("%s   %d\n",s2.str,strlen(s2.str)); 
	
	GetNext(s2,next);
	pos = KMPIndex(s1,pos,s2,next);
	printf("pos = %d\n",pos);
	
	pos = KMPIndex(s1,pos+1,s2,next);
	printf("pos = %d\n",pos);

	Destroy(&s1);
	Destroy(&s2);
		
}
