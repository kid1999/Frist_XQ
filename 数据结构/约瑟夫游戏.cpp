#include<iostream>
#include<stdlib.h> 
using namespace std;

//����һ������
typedef struct People{
	int data;
	struct People *next;
}LinkList;

//��������(30����) 
LinkList *creat(int n){		//����һ������ָ�����͵ķ��� 
	LinkList *head,*node,*end;
	int i;
	head = (LinkList*)malloc(sizeof(LinkList));	//�����ڴ�ռ� 
	end = head;
	head->data=1;
	
	for(i=2;i<n+1;i++){
		node = (LinkList*)malloc(sizeof(LinkList));
		node->data = i;
		end->next = node;
		end = node;
	}
	end->next = head;		//ѭ������ 
	return head;
}

void del(LinkList *list,int n,int x){	//��x��,����Ϊx 
	LinkList *t =list;
	LinkList *temp = t;
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<x-1;j++){
			t = t->next; 
		}
		cout<<"ɾ��������:"<<t->data<<endl;
		temp = t;
		temp->next= temp->next->next; 	//ɾ��9 
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
