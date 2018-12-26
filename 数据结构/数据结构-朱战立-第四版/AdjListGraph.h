
// 邻接表 建立 图
typedef struct Node{
	int dest;	//邻接边的弧头顶点序号
	struct Node *next;	//下一个节点 
}Edge;

typedef struct{
	DataType data;		//顶点数据元素
	int source;			//邻接边的弧尾顶点序号
	Edge *adj;	 		//邻接边单链表的节点结构体 
}AdjLHeight;		//数组数据元素类型结构体

typedef struct {
	AdjLHight a[MaxVertices];		//邻接表数组
	int numOfVerts;			// 顶点个数
	int numOfEdges;			// 边个数 
}AdjLGraph;


// 初始化
void AdjInitiate(AdjLGraph *g){
	int i;
	g->numOfEdges = 0;
	g->numOfVerts = 0;
	for(i=0;i<MaxVertices;i++){
		g->a[i].source = i;		//置邻接边的弧头顶点序号
		g->a[i].adj = NULL;		//置邻接边单链表头指针初值 
	}
}

// 插入顶点
void InsertVertex(AdjLGraph *g,int i,DataType vertex){
	if(i>=0 && i< MaxVertices){
		g->a[i].data = vertex;		//存储顶点数据元素
		g->numOfVerts++;			//个数+1 
	}
	else	printf("顶点越界\n"); 
} 

//插入边
void InsertEdge(AdjLGraph *g,int v1,int v2){
	Edge *p;
	if(v1<0 || v1 >=g->numOfVerts || v2<0 || v2>=g->numOfVerts){
		printf("参数v1 v2 越界错误\n");
		return ;
	}
	p = (Edge*)malloc(sizeof(Edge));		//申请邻接边单链表节点空间
	p->dest = v2;		// 置邻接边弧头序号
	
	p->next = g->a[v1].adj;		//新节点插入单链表的表头
	g->a[v1].adj = p;			//头指针指向新的单链表的表头
	g->numOfEdges ++;			//边数+1 
} 

// 删除边
void DeleteEdge(AdjLGraph *g,int v1,int v2){
	Edge *curr,*pre;
	if(v1<0 || v1 >=g->numOfVerts || v2<0 || v2>=g->numOfVerts){
		printf("参数v1 v2 越界错误\n");
		return ;
	}
	pre = NULL;
	curr = g->a[v1].adj;
	while (curr != NULL && curr->dest != v2){
		//在 v1 顶点 的邻接边 单链表 查找v2顶点
		pre = curr;
		curr = curr->next; 
	}
	
	if(curr != NULL && curr->dest == v2 && pre == NULL){
		// 邻接边 的节点是 单链表第一个节点时
		g->a[v1].adj = curr->next;
		free(curr);
		g->numOfEdges --; 
	}
	else if(curr != NULL && curr->dest == v2 && pre != NULL){
		pre->next = curr->next;
		free(curr);
		g->numOfEdges --;
	}
	else
		printf("边<v1,v2>不存在\n");	
} 

// 取第一个邻接顶点
int GetFirstVex(AdjLGraph g,int v){
	//取图中顶点v 的 第一个邻接顶点
	Edge *p;
	if(v<0 || v>=g.numOfVerts){
		printf("参数v1 v2 越界出错\n");
		return -1;
	} 
	p = g.a[v].adj;
	if(p!=NULL) return p->dest;		//返回该邻接顶点的序号
	else return -1; 
} 

// 取下一个邻接顶点
int GetNextVex(AdjLGraph g,int v1,const int v2){
	// 取 图中 顶点v1 的邻接顶点v2 的下一个邻接顶点
	Edge *p;
	if(v1<0 || v1>=g.numOfVerts || v2 <0 || v2>= g.numOfVerts){
		printf("参数v1 v2 越界出错\n");
		return -1;
	} 
	
	p = g.a[v1].adj;
	while(p != NULL){
		if(p->dest != v2){
			p = p->next;
			continue;
		}
		else break;
	}
	
	p = p->next;			//p 指向 邻接顶点v2 的下一个邻接顶点 
	if(p != NULL) return p->dest;	//返回该邻接顶点对应的序号
	else return -1; 
} 

// 撤销
void AdjDestroy(AdjLGraph *g){
	int i;
	Edge *p,*q;
	for(i=0;i<g->numOfVerts;i++)
	{
		p = g->a[i].adj;
		while(p!=NULL){
			q = p->next;
			free(p);
			p = q;
		}
	}
} 

// 创建图
typedef struct {
	int row;
	int col;
}RowCol;		//边信息结构体

void CreateGraph(AdjLGraph *g,DataType v[],int n,RowCol d[],int e){
	// 创建n个顶点e条边的图g
	int i,k;
	AdjInitiate(g);
	for(i=0;i<n;i++) InsertVertex(g,i,v[i])	// 插入顶点
	for(k = 0;k<n;k++) InsertEdge(g,d[k].row,d[k].col);	//插入边 
} 
