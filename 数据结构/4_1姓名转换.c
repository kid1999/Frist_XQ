#include<stdio.h>
#include<string.h>

void ReverseName(char *name,char *newName){
	char *p;
	p = strchr(name,' ');	// p ָ��ո�λ��
	*p = '\0';	// �ո�Ϊ\0
	
	strcpy(newName,p+1);	// p+1 ָ�� name
	strcat(newName,",");    //newname = �� + ,
	strcat(newName,name);	//newname = �� + , + ��
	*p = ' ';	//�ָ�name��ʼ״̬ 
} 

main(){
	char name[] = "Hello World",newName[30];
	ReverseName(name,newName);
	printf("ת���������: %s\n",newName); 
} 
