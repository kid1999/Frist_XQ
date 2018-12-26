
//  �ڽӾ��� ���� ͼ
#include "SeqList.h"
typedef struct {
	SeqList Vertices;	//��Ŷ����˳���
	int edge[MaxVertices][MaxVertices];		//��űߵ��ڽӾ���
	int numOfEdge;		//�ߵĸ��� 
}AdjMGraph;				//ͼ�Ľṹ�嶨��

// init
void Init(AdjMGraph *g,int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j) g->edge[i][j] = 0;
			else g->edge[i][j] = MaxWeight;		//���޴� 
		}
	}
	g->numOfEdge = 0;				// �ߵ�������0 
	ListInitiate(&g->Vertices);		//˳����ʼ�� 
} 

// ���붥��
void InsertVertex(AdjMGraph *g,DataType vertex){
	ListInsert(&g->Vertices,g->Vertices.size,vertex);	//˳���β������ 
} 

// ����� 
void  InsertEdge(AdjMGraph *g,int v1,int v2,int weight){
	//ͼG �����<v1,v2>  ȨΪweight
	if(v1<0 || v1>g->Vertices.size || v2<0 || v2 > g->Vertices.size) {
		printf("���� v1 v2 Խ�����\n");
		return ; 
	}
	g->edge[v1][v2] = weight;
	g->numOfEdge ++;
} 

//ɾ����
void DeleteEdge(AdjMGraph *g,int v1,int v2){
	// ��ͼ ��ɾ�� <v1,v2>
	if(v1<0 || v1>g->Vertices.size || v2<0 || v2 > g->Vertices.size) {
		printf("���� v1 v2 Խ�����\n");
		return ; 
	}
	if(g->edge[v1][v2] == MaxWeight || v1 == v2){
		printf("�ñ߲�����\n");
		return ;
	}
	g->edge[v1][v2] = MaxWeight;
	g->numOfEdge --;
} 

// ȡ��һ�� �ڽӶ���
int GetFirstVex(AdjMGraph g,int v){
	// ��ͼ �� Ѱ�� ���Ϊv�Ķ���ĵ�һ���ڽӶ���
	int col;
	if(v<0 || v>=g.Vertices.size){
		printf("����v Խ�����\n");
		return -1;
	} 
	for(col= 0;col <g.Vertices.size;col++)
		if(g.edge[v][col]> 0 && g.edge[v][col] <MaxWeight) return col;
	return -1;
}

// ȡ��һ�� �ڽӶ���
int GetNextVex(AdjMGraph g,int v1,int v2){
	// ��ͼg  ��Ѱ�� �ڽӶ���v2 ����һ���ڽӶ��� 
	int col;
	if(v1<0 || v1>g.Vertices.size || v2<0 || v2 > g.Vertices.size) {
		printf("���� v1 v2 Խ�����\n");
		return -1; 
	}
	
	for(col = v2+1;col<g.Vertices.size;col++)
		if(g.edge[v1][col] >0 && g.edge[v1][col] <MaxWeight) return col;
	return -1; 
} 
