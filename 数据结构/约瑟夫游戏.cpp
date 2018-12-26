#include<iostream>
#include<stdlib.h> 
using namespace std;

//定义一个链表
typedef struct People{
	int data;
	struct People *next;
}LinkList;

//创建链表(30个人) 
LinkList *creat(int n){		//创建一个返回指针类型的方法 
	LinkList *head,*node,*end;
	int i;
	head = (LinkList*)malloc(sizeof(LinkList));	//开辟内存空间 
	end = head;
	head->data=1;
	
	for(i=2;i<n+1;i++){
		node = (LinkList*)malloc(sizeof(LinkList));
		node->data = i;
		end->next = node;
		end = node;
	}
	end->next = head;		//循环链表 
	return head;
}

void del(LinkList *list,int n,int x){	//扔x人,步进为x 
	LinkList *t =list;
	LinkList *temp = t;
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<x-1;j++){
			t = t->next; 
		}
		cout<<"删除的数据:"<<t->data<<endl;
		temp = t;
		temp->next= temp->next->next; 	//删除9 
		free(t->next);
	}

}

main(){
	LinkList *head = creat(30);
//	for(int i=0;i<50;i++){
//		cout<<head->data<<endl;
//		head = head->next;
//	}
	del(head,15,9);
	
	

	cout<<"hello "<<endl;
}  
