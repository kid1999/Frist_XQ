
// ��������  ����С��Ȩ���� 
typedef struct {
	int weight;		//Ȩֵ
	int flag;		//���
	int parent;		//˫�׽ڵ��±�
	int leftChild;	//�����±�
	int rightChild;	//�Һ����±� 
}HaffNode;

typedef struct {
	int bit[MaxN];		//����
	int start;			//���뿪ʼ�±�
	int weight;			//�ַ���Ȩֵ  
}Code;

//������������ 
void  Haffman(int weight[],int n,HaffNode haffTree[]){
	// ���� Ҷ�ڵ��� Ϊn,   Ȩֵ����Ϊweight  �� ��������
	int  i,j,m1,m2,x1,x2;
	 
	// ���������ĳ�ʼ��
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
		for(j=0;i<n-1;j++)	//�ҳ�Ȩֵ��С�ʹ�С������
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
		 
		 // ������Ȩֵ��С���� �ϲ�Ϊһ������
		 haffTree[x1].parent = n+i;
		 haffTree[x2].parent = n+i;
		 haffTree[x1].flag = 1;
		 haffTree[x2].flag = 1;
		 haffTree[n+i],weight = haffTree[x1].weight + haffTree[x2].weight;
		 haffTree[n+i].leftChild = x1;
		 haffTree[n+i].rightChild = x2; 
	} 
} 

// ���������� 
void HaffmanCode(HaffNode haffTree[],int n,Code haffCode[]){
	// �� n���ڵ�Ĺ�������  ���� ����������haffcode
	Code *cd = (Code*)malloc(sizeof(Code));
	int i,j,child,parent;
	
	//��n��Ҷ�ڵ�Ĺ���������
	for(i=0;i<n;i++){
		cd->start = n-1;	//���ȳ���������һλ��n-1
		cd->weight = haffTree[i].weight;	//ȡ�ñ����Ӧ��Ȩֵ
		child = i;
		parent = haffTree[child].parent;
		
		//Ҷ�ڵ� ����  ֱ�� ���ڵ�
		while(parent != -1){
			if(haffTree[parent].leftChild == child)
				cd->bit[cd->start] = 0;		//���ӷ�֧����0
			else
				cd->bit[cd->start] = 1;		//�Һ��ӷ�֧����1
			
			cd->start--;
			child = parent;
			parent = haffTree[child].parent;
		}
		for(j = cd->start+1;j<n;j++)		
			haffCode[i].bit[j] = cd->bit[j];	//����ÿ��Ҷ�ӽڵ�ı��� 
		haffCode[i].start = cd->start+1;	//����Ҷ�ӱ������ʼλ
		haffCode[i].weight = cd->weight;	//��������Ӧ��Ȩֵ 
	}
} 
