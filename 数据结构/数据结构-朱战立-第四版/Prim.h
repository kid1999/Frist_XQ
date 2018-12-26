
// 最小生成树
		//  普利姆算法

// 最小生成树的顶点 及其 边权值 信息结构体 
typedef struct {
	VerT vertex;
	int weight;
}MinSpanTree;

void Pirm(AdjMGraph g,MinSpanTree closeVertex[]){
	// 普利姆算法 建立带权tu 的最小生成树
	VerT x;
	int n = g.Vertices.size,minCost;
	int *lowCost = (int*)malloc(sizeof(int)*n);
	int i,j,k;
	
	for(i=1;i<n;i++)
		lowCost[i] = g.edge[0][i];		//初始化
	
	// 从顶点0 开始构建
	ListGet(g.Vertices,0,&x);	//取顶点0
	closeVertex[0].vertex = x;	//保存顶点0
	lowCost[0] = -1;		//标记顶点0
	
	for(i=1;i<n;i++){
		// 寻找 当前权值最小的边对应的弧头顶点k
		minCost = MaxWeight;		//MaxWeight 定义最大权值
		for(j=1;j<n;j++){
			if(lowCost[j] < minCost && lowCost[j] >0){
				minCost = lowCost[j];
				k = j; 
			}
		} 
	} 
	
	ListGet(g.Vertices,k,&x);		//取弧头顶点
	closeVertex[i].vertex = x;		//保存弧头顶点k
	closeVertex[i].weight = minCost;	//存储对应权值
	lowCost[k] = -1;		//标记k 
	
	// 根据加入集合u的顶点k 修改lowcost 中的数值
	for(j=1;j<n;j++){
		if(g.edge[k][j] < lowCost[j])
			lowCost[j] = g.edge[k][j];
	} 
} 
