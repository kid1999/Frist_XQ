
// 哈夫曼树 的 构建
#include<stdio.h>
#include<stdlib.h>
typedef int DataType;

// 结构体 
typedef struct Node{
	DataType data;	//数据域
	struct Node *leftChild;
	struct Node *rightChild;	//右子树指针 
}BiTreeNode;

// init
void Initiate(BiTreeNode **root){
	*root = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	(*root)->leftChild = NULL;
	(*root)->rightChild = NULL;
} 

// 左插入节点 
//若原来左节点 为空 新插入左节点
//若原来非空  原来的数据插入新节点的左节点
BiTreeNode *InsertLeftNode(BiTreeNode *curr,DataType x){
	BiTreeNode *s,*t;
	if(curr == NULL) return NULL;
	t = curr->leftChild;	//保存原来的左子树指针
	s = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	s->data = x;
	s->leftChild = t;
	s->rightChild = NULL;
	
	curr->leftChild = s;	//新节点成为 curr左子树
	return curr->leftChild; 
} 

//右插入节点 
BiTreeNode *InsertRightNode(BiTreeNode *curr,DataType x){
	BiTreeNode *s,*t;
	if(curr == NULL) return NULL;
	t = curr->rightChild;	//保存原来的右子树指针
	s = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	s->data = x;
	s->rightChild = t;
	s->leftChild = NULL;
	
	curr->rightChild = s;	//新节点成为 curr左子树
	return curr->rightChild; 
}


// 撤销二叉树
void Destroy(BiTreeNode **root){
	if((*root) != NULL && (*root)->leftChild != NULL) 
		Destroy(&(*root)->leftChild);
	if((*root) != NULL && (*root)->rightChild != NULL) 
		Destroy(&(*root)->rightChild);
	free(*root);
} 

//左删除子树
//若 curr 非空 删除curr所指子树
//删除成功返回双亲节点指针
BiTreeNode *DeleteLeftTree(BiTreeNode *curr){
	if(curr == NULL || curr->leftChild == NULL) return NULL;
	
	Destroy(&curr->leftChild);
	curr->leftChild = NULL;
	return curr;
} 

//右删除子树
BiTreeNode *DeleteRightTree(BiTreeNode *curr){
	if(curr == NULL || curr->leftChild == NULL) return NULL;
	
	Destroy(&curr->leftChild);
	curr->leftChild = NULL;
	return curr;
} 

		//  遍历  二叉树
// 显示节点信息 
void visit(DataType item){
	printf("%d   ",item); 
}

// 先序遍历
void  preOrder(BiTreeNode *root,void visit(DataType item)){
	if(root != NULL){
		visit(root->data);		//中 
		preOrder(root->leftChild,visit);	//左 
		preOrder(root->rightChild,visit);	//右 
	}
} 

//中序遍历
void  inOrder(BiTreeNode *root,void visit(DataType item)){
	if(root != NULL){
		inOrder(root->leftChild,visit);	//左 
		visit(root->data);		//中 
		inOrder(root->rightChild,visit);	//右 
	}
} 

//后序遍历
void  PosOrder(BiTreeNode *root,void visit(DataType item)){
	if(root != NULL){
		PosOrder(root->leftChild,visit);	//左 
		PosOrder(root->rightChild,visit);	//右 
		visit(root->data);		//中 
	}
} 


// 打印 二叉树
void PrintBiTree(BiTreeNode *root,int n){
	int i;
	if(root == NULL) return;	// 递归出口
	PrintBiTree(root->rightChild,n+1);	//遍历打印右子树
	
	// 访问根节点
	for(i=0;i<n-1;i++)  printf("     ");
	if(n >0)
	{
		printf("---");
		printf("%d\n",root->data);
	 } 
	
	PrintBiTree(root->leftChild,n+1);		// 遍历打印左子树 
} 



			// 主函数 
main(){
	int a[] = {4,2,6,9};
	int n = 4,i,j,tmp;
	BiTreeNode *root,*p;
	
	
	//sort	
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j] > a[j+1]){
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			} 
		}
	}
	
	// 按最大的数字 插入 左子树 右子树为空 直到null
	Initiate(&root);
	p = InsertLeftNode(root,-1);	//root

	for(i=n-1;i>1;i--){
		InsertLeftNode(p,a[i]);
		p = InsertRightNode(p,-1);		
	}
	InsertLeftNode(p,a[1]);
	InsertRightNode(p,a[0]);
	
	
	// display
	PrintBiTree(root,0);
	
	// 
	printf("\n中序遍历\n");
	inOrder(root->leftChild,visit);
	
	//dispaly
//	for(i=0;i<n;i++){
//		printf("%d ",a[i]);
//	}
}
