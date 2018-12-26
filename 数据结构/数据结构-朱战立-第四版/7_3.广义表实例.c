#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef char DataType;
#include "GList.h"

main(){
	char str1[] = "(((a,b,c),(d)),e)";
	char str2[] = "(((a,b,c),(d)),e)";
	char hstr[100];
	GLNode *p,*h;
	int depth,number,length;
	
	h = CreatGList(str1);
	printf("广义表str1 = %s",str2);
	DecomposeStr(str2,hstr);
	printf("\n表头 =%s",hstr);
	printf("\n表尾 =%s",str2);
	
	depth = GListDepth(h);
	printf("\n深度 =%d",depth);
	length = GListLength(h);
	printf("\n长度 = %d",length);
	number = GListAtomNum(h);
	printf("\n原子元素个数: %d",number);
	
	p = GListSearch(h,'a');
	if(p != NULL)	printf("111");//printf("\n数据元素%c 在广义表中",p->val.atom);
	else  printf("\n广义表中找不到元素.");
	
	DestroyGlist(h);
} 
