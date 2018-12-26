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
	
	PrintBiTree(root,0);		// 打印
	
	printf("\n前序遍历\n");
	preOrder(root->leftChild,visit);
	printf("\n中序遍历\n");
	inOrder(root->leftChild,visit);
	printf("\n后序遍历\n");
	PosOrder(root->leftChild,visit); 
	
	find = Search(root,'E');
	if(find != NULL)
		printf("\n 数据元素%c 在二叉树中。");
	else
		printf("\n 数据元素%c 不在二叉树中。");
	Destroy(&root); 
}
