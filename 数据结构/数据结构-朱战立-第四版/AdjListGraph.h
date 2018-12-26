
// �ڽӱ� ���� ͼ
typedef struct Node{
	int dest;	//�ڽӱߵĻ�ͷ�������
	struct Node *next;	//��һ���ڵ� 
}Edge;

typedef struct{
	DataType data;		//��������Ԫ��
	int source;			//�ڽӱߵĻ�β�������
	Edge *adj;	 		//�ڽӱߵ�����Ľڵ�ṹ�� 
}AdjLHeight;		//��������Ԫ�����ͽṹ��

typedef struct {
	AdjLHight a[MaxVertices];		//�ڽӱ�����
	int numOfVerts;			// �������
	int numOfEdges;			// �߸��� 
}AdjLGraph;


// ��ʼ��
void AdjInitiate(AdjLGraph *g){
	int i;
	g->numOfEdges = 0;
	g->numOfVerts = 0;
	for(i=0;i<MaxVertices;i++){
		g->a[i].source = i;		//���ڽӱߵĻ�ͷ�������
		g->a[i].adj = NULL;		//���ڽӱߵ�����ͷָ���ֵ 
	}
}

// ���붥��
void InsertVertex(AdjLGraph *g,int i,DataType vertex){
	if(i>=0 && i< MaxVertices){
		g->a[i].data = vertex;		//�洢��������Ԫ��
		g->numOfVerts++;			//����+1 
	}
	else	printf("����Խ��\n"); 
} 

//�����
void InsertEdge(AdjLGraph *g,int v1,int v2){
	Edge *p;
	if(v1<0 || v1 >=g->numOfVerts || v2<0 || v2>=g->numOfVerts){
		printf("����v1 v2 Խ�����\n");
		return ;
	}
	p = (Edge*)malloc(sizeof(Edge));		//�����ڽӱߵ�����ڵ�ռ�
	p->dest = v2;		// ���ڽӱ߻�ͷ���
	
	p->next = g->a[v1].adj;		//�½ڵ���뵥����ı�ͷ
	g->a[v1].adj = p;			//ͷָ��ָ���µĵ�����ı�ͷ
	g->numOfEdges ++;			//����+1 
} 

// ɾ����
void DeleteEdge(AdjLGraph *g,int v1,int v2){
	Edge *curr,*pre;
	if(v1<0 || v1 >=g->numOfVerts || v2<0 || v2>=g->numOfVerts){
		printf("����v1 v2 Խ�����\n");
		return ;
	}
	pre = NULL;
	curr = g->a[v1].adj;
	while (curr != NULL && curr->dest != v2){
		//�� v1 ���� ���ڽӱ� ������ ����v2����
		pre = curr;
		curr = curr->next; 
	}
	
	if(curr != NULL && curr->dest == v2 && pre == NULL){
		// �ڽӱ� �Ľڵ��� �������һ���ڵ�ʱ
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
		printf("��<v1,v2>������\n");	
} 

// ȡ��һ���ڽӶ���
int GetFirstVex(AdjLGraph g,int v){
	//ȡͼ�ж���v �� ��һ���ڽӶ���
	Edge *p;
	if(v<0 || v>=g.numOfVerts){
		printf("����v1 v2 Խ�����\n");
		return -1;
	} 
	p = g.a[v].adj;
	if(p!=NULL) return p->dest;		//���ظ��ڽӶ�������
	else return -1; 
} 

// ȡ��һ���ڽӶ���
int GetNextVex(AdjLGraph g,int v1,const int v2){
	// ȡ ͼ�� ����v1 ���ڽӶ���v2 ����һ���ڽӶ���
	Edge *p;
	if(v1<0 || v1>=g.numOfVerts || v2 <0 || v2>= g.numOfVerts){
		printf("����v1 v2 Խ�����\n");
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
	
	p = p->next;			//p ָ�� �ڽӶ���v2 ����һ���ڽӶ��� 
	if(p != NULL) return p->dest;	//���ظ��ڽӶ����Ӧ�����
	else return -1; 
} 

// ����
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

// ����ͼ
typedef struct {
	int row;
	int col;
}RowCol;		//����Ϣ�ṹ��

void CreateGraph(AdjLGraph *g,DataType v[],int n,RowCol d[],int e){
	// ����n������e���ߵ�ͼg
	int i,k;
	AdjInitiate(g);
	for(i=0;i<n;i++) InsertVertex(g,i,v[i])	// ���붥��
	for(k = 0;k<n;k++) InsertEdge(g,d[k].row,d[k].col);	//����� 
} 
