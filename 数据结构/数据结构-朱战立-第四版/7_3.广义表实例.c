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
	printf("�����str1 = %s",str2);
	DecomposeStr(str2,hstr);
	printf("\n��ͷ =%s",hstr);
	printf("\n��β =%s",str2);
	
	depth = GListDepth(h);
	printf("\n��� =%d",depth);
	length = GListLength(h);
	printf("\n���� = %d",length);
	number = GListAtomNum(h);
	printf("\nԭ��Ԫ�ظ���: %d",number);
	
	p = GListSearch(h,'a');
	if(p != NULL)	printf("111");//printf("\n����Ԫ��%c �ڹ������",p->val.atom);
	else  printf("\n��������Ҳ���Ԫ��.");
	
	DestroyGlist(h);
} 
