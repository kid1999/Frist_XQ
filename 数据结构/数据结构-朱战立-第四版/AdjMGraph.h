
//  邻接矩阵 构建 图
#include "SeqList.h"
typedef struct {
	SeqList Vertices;	//存放顶点的顺序表
	int edge[MaxVertices][MaxVertices];		//存放边的邻接矩阵
	int numOfEdge;		//边的个数 
}AdjMGraph;				//图的结构体定义

// init
void Init(AdjMGraph *g,int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j) g->edge[i][j] = 0;
			else g->edge[i][j] = MaxWeight;		//无限大 
		}
	}
	g->numOfEdge = 0;				// 边的条数置0 
	ListInitiate(&g->Vertices);		//顺序表初始化 
} 

// 插入顶点
void InsertVertex(AdjMGraph *g,DataType vertex){
	ListInsert(&g->Vertices,g->Vertices.size,vertex);	//顺序表尾部插入 
} 

// 插入边 
void  InsertEdge(AdjMGraph *g,int v1,int v2,int weight){
	//图G 插入边<v1,v2>  权为weight
	if(v1<0 || v1>g->Vertices.size || v2<0 || v2 > g->Vertices.size) {
		printf("参数 v1 v2 越界错误\n");
		return ; 
	}
	g->edge[v1][v2] = weight;
	g->numOfEdge ++;
} 

//删除边
void DeleteEdge(AdjMGraph *g,int v1,int v2){
	// 在图 中删除 <v1,v2>
	if(v1<0 || v1>g->Vertices.size || v2<0 || v2 > g->Vertices.size) {
		printf("参数 v1 v2 越界错误\n");
		return ; 
	}
	if(g->edge[v1][v2] == MaxWeight || v1 == v2){
		printf("该边不存在\n");
		return ;
	}
	g->edge[v1][v2] = MaxWeight;
	g->numOfEdge --;
} 

// 取第一个 邻接顶点
int GetFirstVex(AdjMGraph g,int v){
	// 在图 中 寻找 序号为v的定点的第一个邻接顶点
	int col;
	if(v<0 || v>=g.Vertices.size){
		printf("参数v 越界出错\n");
		return -1;
	} 
	for(col= 0;col <g.Vertices.size;col++)
		if(g.edge[v][col]> 0 && g.edge[v][col] <MaxWeight) return col;
	return -1;
}

// 取下一个 邻接顶点
int GetNextVex(AdjMGraph g,int v1,int v2){
	// 在图g  中寻找 邻接顶点v2 的下一个邻接顶点 
	int col;
	if(v1<0 || v1>g.Vertices.size || v2<0 || v2 > g.Vertices.size) {
		printf("参数 v1 v2 越界错误\n");
		return -1; 
	}
	
	for(col = v2+1;col<g.Vertices.size;col++)
		if(g.edge[v1][col] >0 && g.edge[v1][col] <MaxWeight) return col;
	return -1; 
} 
