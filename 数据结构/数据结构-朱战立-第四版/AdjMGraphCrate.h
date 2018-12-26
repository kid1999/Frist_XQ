// 带权有向图
typedef struct {
	int row;	//行
	int col;	//列
	int weight;	//权值 
}RowColWeight;	//边信息结构体定义

void CreatGraph(AdjMGraph *g,DataType V[],int n,RowColWeight E[],int e){
	// 在g 中插入 n个顶点信息 V 和 e 条边信息 E
	int  i,k;
	Init(g,n);	//顶点顺序表初始化
	for(i=0;i<n;i++)
		InsertVertex(g,V[i]);	//插入顶点 
	
	for(k=0;k<e;k++)
		InsertEdge(g,E[k].row,E[k].col,E[k].weight);	//插入边 
} 

