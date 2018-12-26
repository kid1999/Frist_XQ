#include<stdio.h>
#include<stdlib.h>

typedef char DataType;
#include "BiTree.h"

main(){
	BiTreeNode *root,*p,*find;
	
	Initiate(&root);
	p = InsertLeftNode(root,'A');
	p = InsertLeftNode(p,'B');
	p = InsertLeftNode(p,'D');
	p = InsertRightNode(p,'G');
	p = InsertRightNode(root->leftChild,'C');
	InsertLeftNode(p,'E');
	InsertRightNode(p,'F');
	
	PrintBiTree(root,0);		// ��ӡ
	
	printf("\nǰ�����\n");
	preOrder(root->leftChild,visit);
	printf("\n�������\n");
	inOrder(root->leftChild,visit);
	printf("\n�������\n");
	PosOrder(root->leftChild,visit); 
	
	find = Search(root,'E');
	if(find != NULL)
		printf("\n ����Ԫ��%c �ڶ������С�");
	else
		printf("\n ����Ԫ��%c ���ڶ������С�");
	Destroy(&root); 
}
