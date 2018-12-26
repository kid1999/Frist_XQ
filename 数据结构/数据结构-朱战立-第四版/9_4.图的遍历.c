#include<stdio.h> 
#include<malloc.h> 
typedef char DataType;
#define MaxSize 10		// ˳����������ֵ 
#define MaxVertices 10		// �������ֵ 
#define MaxWeight 10000 	// ���������ľ���ֵ

#include "AdjMGraph.h" 
#include "AdjMGraphCrate.h"

void Visit(DataType item){
	// ���� ���ʺ���
	printf("%c   ",item); 
}
// ��ͨͼ��������ȱ���
void DepthFSearch(AdjMGraph g,int v,int visited[],void Visit(DataType item)){
	// ��ͨͼg �� v Ϊ��ʼ������ ���� vist() ��������ȱ���
	// visted �����Ƿ��Ѿ����ʹ�
	int w;
	Visit(g.Vertices.list[v]);	//���ʽڵ� v
	visited[v] = 1;
	
	w = GetFirstVex(g,v);	//ȡ��һ���ڽӶ���
	while(w != -1){
		if(! visited[w])
			DepthFSearch(g,w,visited,Visit);	//�ݹ� 
		w = GetNextVex(g,v,w);		//ȡ��һ�� �ڽӶ��� 
	} 
}
 
// ����ͨͼ��������ȱ���
void DepthFirstSearch(AdjMGraph g,void Visit(DataType item)){
	int i;
	int *visited = (int *)malloc(sizeof(int)*g.Vertices.size);
	for(i=0;i<g.Vertices.size;i++)
		visited[i] = 0;			//��ʼΪ0
	for(i=0;i<g.Vertices.size;i++)
		if(! visited[i]) 
			DepthFSearch(g,i,visited,Visit);		//��ÿһ������Ϊ��ʼ���㿪ʼ����
	free(visited); 
} 



// ������ȱ��� 



main(){
	AdjMGraph g1;
	DataType a[] = {'A','B','C','D','E'} ;
	RowColWeight rcw[] = {{0,1,10},{0,4,20},{1,3,30},{2,1,40},{3,2,50}};
	int n=5,e=5;
	int i,j;
	
	CreatGraph(&g1,a,n,rcw,e);		//����ͼ
	
		printf("���㼯��Ϊ: ");
	for(i=0;i<g1.Vertices.size;i++)
		printf("%c  ",g1.Vertices.list[i]);
	printf("\n"); 
	
	DepthFirstSearch(g1,Visit);
} 
