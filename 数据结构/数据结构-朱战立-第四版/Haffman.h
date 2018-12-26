
// 哈夫曼树  （最小加权树） 
typedef struct {
	int weight;		//权值
	int flag;		//标记
	int parent;		//双亲节点下标
	int leftChild;	//左孩子下标
	int rightChild;	//右孩子下标 
}HaffNode;

typedef struct {
	int bit[MaxN];		//数组
	int start;			//编码开始下标
	int weight;			//字符的权值  
}Code;

//构建哈夫曼树 
void  Haffman(int weight[],int n,HaffNode haffTree[]){
	// 建立 叶节点数 为n,   权值数组为weight  的 哈夫曼树
	int  i,j,m1,m2,x1,x2;
	 
	// 哈夫曼树的初始化
	for(i=0;i<2*n-1;i++){
		if(i<n) haffTree[i].weight = weight[i];
		else  haffTree[i].weight  =0;
		haffTree[i].parent = -1;
		haffTree[i].flag = 0;
		haffTree[i].leftChild = -1;
		haffTree[i].rightChild = -1;
	} 
	
	for(i= 0;i<n-1;i++){
		m1 = m2 = MaxValue;
		x1 = x2 = 0;
		for(j=0;i<n-1;j++)	//找出权值最小和次小的子树
		{
			if(haffTree[j].weight <m1 && haffTree[j].flag == 0){
				m2 = m1;
				x2 = x1;
				m1 = haffTree[j].weight;
				x1 = j;
			}
			else if (haffTree[j].weight <m2 && haffTree[j].flag ==0){
				m2 = haffTree[j].weight;
				x2 = j;
			}
		 }
		 
		 // 将两颗权值最小的树 合并为一颗子树
		 haffTree[x1].parent = n+i;
		 haffTree[x2].parent = n+i;
		 haffTree[x1].flag = 1;
		 haffTree[x2].flag = 1;
		 haffTree[n+i],weight = haffTree[x1].weight + haffTree[x2].weight;
		 haffTree[n+i].leftChild = x1;
		 haffTree[n+i].rightChild = x2; 
	} 
} 

// 哈夫曼编码 
void HaffmanCode(HaffNode haffTree[],int n,Code haffCode[]){
	// 由 n个节点的哈夫曼树  构造 哈夫曼编码haffcode
	Code *cd = (Code*)malloc(sizeof(Code));
	int i,j,child,parent;
	
	//求n个叶节点的哈夫曼编码
	for(i=0;i<n;i++){
		cd->start = n-1;	//不等长编码的最后一位是n-1
		cd->weight = haffTree[i].weight;	//取得编码对应的权值
		child = i;
		parent = haffTree[child].parent;
		
		//叶节点 向上  直到 根节点
		while(parent != -1){
			if(haffTree[parent].leftChild == child)
				cd->bit[cd->start] = 0;		//左孩子分支编码0
			else
				cd->bit[cd->start] = 1;		//右孩子分支编码1
			
			cd->start--;
			child = parent;
			parent = haffTree[child].parent;
		}
		for(j = cd->start+1;j<n;j++)		
			haffCode[i].bit[j] = cd->bit[j];	//保存每个叶子节点的编码 
		haffCode[i].start = cd->start+1;	//保存叶子编码的起始位
		haffCode[i].weight = cd->weight;	//保存编码对应的权值 
	}
} 
