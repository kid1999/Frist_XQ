#include<stdio.h> 
#include<malloc.h> 
typedef char DataType;
#define MaxSize 10		// 顺序表数组最大值 
#define MaxVertices 10		// 顶点最大值 
#define MaxWeight 10000 	// 定义无穷大的具体值

#include "AdjMGraph.h" 
#include "AdjMGraphCrate.h"

void Visit(DataType item){
	// 定制 访问函数
	printf("%c   ",item); 
}
// 联通图的深度优先遍历
void DepthFSearch(AdjMGraph g,int v,int visited[],void Visit(DataType item)){
	// 连通图g 以 v 为初始化顶点 访问 vist() 的深度优先遍历
	// visted 代表是否已经访问过
	int w;
	Visit(g.Vertices.list[v]);	//访问节点 v
	visited[v] = 1;
	
	w = GetFirstVex(g,v);	//取第一个邻接顶点
	while(w != -1){
		if(! visited[w])
			DepthFSearch(g,w,visited,Visit);	//递归 
		w = GetNextVex(g,v,w);		//取下一个 邻接顶点 
	} 
}
 
// 非连通图的深度优先遍历
void DepthFirstSearch(AdjMGraph g,void Visit(DataType item)){
	int i;
	int *visited = (int *)malloc(sizeof(int)*g.Vertices.size);
	for(i=0;i<g.Vertices.size;i++)
		visited[i] = 0;			//初始为0
	for(i=0;i<g.Vertices.size;i++)
		if(! visited[i]) 
			DepthFSearch(g,i,visited,Visit);		//以每一个顶点为初始顶点开始调用
	free(visited); 
} 



// 广度优先遍历 



main(){
	AdjMGraph g1;
	DataType a[] = {'A','B','C','D','E'} ;
	RowColWeight rcw[] = {{0,1,10},{0,4,20},{1,3,30},{2,1,40},{3,2,50}};
	int n=5,e=5;
	int i,j;
	
	CreatGraph(&g1,a,n,rcw,e);		//构建图
	
		printf("顶点集合为: ");
	for(i=0;i<g1.Vertices.size;i++)
		printf("%c  ",g1.Vertices.list[i]);
	printf("\n"); 
	
	DepthFirstSearch(g1,Visit);
} 
