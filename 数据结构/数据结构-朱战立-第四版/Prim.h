
// ��С������
		//  ����ķ�㷨

// ��С�������Ķ��� ���� ��Ȩֵ ��Ϣ�ṹ�� 
typedef struct {
	VerT vertex;
	int weight;
}MinSpanTree;

void Pirm(AdjMGraph g,MinSpanTree closeVertex[]){
	// ����ķ�㷨 ������Ȩtu ����С������
	VerT x;
	int n = g.Vertices.size,minCost;
	int *lowCost = (int*)malloc(sizeof(int)*n);
	int i,j,k;
	
	for(i=1;i<n;i++)
		lowCost[i] = g.edge[0][i];		//��ʼ��
	
	// �Ӷ���0 ��ʼ����
	ListGet(g.Vertices,0,&x);	//ȡ����0
	closeVertex[0].vertex = x;	//���涥��0
	lowCost[0] = -1;		//��Ƕ���0
	
	for(i=1;i<n;i++){
		// Ѱ�� ��ǰȨֵ��С�ı߶�Ӧ�Ļ�ͷ����k
		minCost = MaxWeight;		//MaxWeight �������Ȩֵ
		for(j=1;j<n;j++){
			if(lowCost[j] < minCost && lowCost[j] >0){
				minCost = lowCost[j];
				k = j; 
			}
		} 
	} 
	
	ListGet(g.Vertices,k,&x);		//ȡ��ͷ����
	closeVertex[i].vertex = x;		//���满ͷ����k
	closeVertex[i].weight = minCost;	//�洢��ӦȨֵ
	lowCost[k] = -1;		//���k 
	
	// ���ݼ��뼯��u�Ķ���k �޸�lowcost �е���ֵ
	for(j=1;j<n;j++){
		if(g.edge[k][j] < lowCost[j])
			lowCost[j] = g.edge[k][j];
	} 
} 
