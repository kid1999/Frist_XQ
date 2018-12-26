#include<stdio.h>
#define MaxSize 100
typedef struct Student{
	long number;
	char name[10];
	char sex[10];
	int age;
}StudentType;

typedef StudentType DataType;		//定义StudentType为 SeqList的数据类型 
# include "SeqList.h"

main(){
	SeqList myList;
	int i;
	StudentType x[3] = {{2001,"kid","man",20},{2002,"hello","woman",19},{2003,"world","man",21}};
	StudentType s;
	ListInitiate(&myList);
	ListInsert(&myList,0,x[0]);
	ListInsert(&myList,1,x[1]);
	ListInsert(&myList,2,x[2]);
	
	for(i=0;i<ListLength(myList);i++){
		ListGet(myList,i,&s);
		printf("%d\t  %s\t  %s\t  %d\n",s.number,s.name,s.sex,s.age);
	}
}
