// ��Ȩ����ͼ
typedef struct {
	int row;	//��
	int col;	//��
	int weight;	//Ȩֵ 
}RowColWeight;	//����Ϣ�ṹ�嶨��

void CreatGraph(AdjMGraph *g,DataType V[],int n,RowColWeight E[],int e){
	// ��g �в��� n��������Ϣ V �� e ������Ϣ E
	int  i,k;
	Init(g,n);	//����˳����ʼ��
	for(i=0;i<n;i++)
		InsertVertex(g,V[i]);	//���붥�� 
	
	for(k=0;k<e;k++)
		InsertEdge(g,E[k].row,E[k].col,E[k].weight);	//����� 
} 

