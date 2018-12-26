//  �����  ��ʽ�洢

typedef struct GListNode{
	int tag;
	union{
		DataType atom;	//ԭ��Ԫ����
		struct{
			struct GListNode *head;	//ͷָ�� 
			struct GListNode *tail;	//βָ�� 
		}subList;	// �ӱ��� 
	}val;
}GLNode;

// ��������� 
void DecomposeStr(char str[],char hstr[]){
	// �� ��ʾ�������ַ��� �ֽ�� ͷ�ַ���hstr �� ��β�ַ���str
	int i,j,tag,n = strlen(str);
	char ch;
	
	ch = str[0];
	tag = 0;
	for(i=0;i<=n-1;i++){
		if(str[i] == ',' && tag == 1)	//���������ĵ�һ������ 
			break;
		ch = str[i];
		if(ch == '(') tag++;
		if(ch == ')') tag--;
	} 
	if(i <= n-1 && str[i] == ',')  // ������β �ǿ�ʱ
		{
			for(j=0;j<i-1;j++)	//ȡ��ͷ�ַ��� 
				hstr[j] = str[j+1];
			
			hstr[j] = '\0';		//��ӽ�����
			
			if(str[i] == ',') i++;
			
			str[0] = '(';
			
			for(j=1;i<=n-2;i++,j++)		//	ȡ��β�ַ��� 
				str[j] = str[i];
			
			str[j] = ')';
			str[++j] = '\0';
		 } 
	else{
		str++;		// ��������ߵ�(
		strncpy(hstr,str,n-2);  //���������ұߵ�)
		hstr[n-2] = '\0';
		str--; 	// �ָ�ָ��λ��
		strcpy(str,"()");	//��βΪ�� 
	}
} 

GLNode* CreatGList(char str[]){
	// ���չ�����ַ��� ���������  ���ع�����ͷָ��
	// str Ϊ��ʾ������ �ַ���
	GLNode *h;
	char hstr[200];
	int len = strlen(str);
	if(strcmp(str,"()") == 0) h = NULL;
	else if(len == 1) 	// ���� ԭ��Ԫ�ؽڵ�
	{
		h = (GLNode *)malloc(sizeof(GLNode));
		h->tag = 0;
		h->val.atom = str[0];
		
	} 
	else{
		// ���� �ӱ�
		h = (GLNode *)malloc(sizeof(GLNode));
		h->tag = 1;
		
		//���ַ��� �ֽ�Ϊ hster �� str
		DecomposeStr(str,hstr);
		h->val.subList.head = CreatGList(str);	// ������ͷ�Ĺ����
		if(strcmp(str,"()") !=0)	//��β�ǿ�ʱ 
			h->val.subList.tail = CreatGList(str);	//������β�Ĺ����
		else	//	��βΪ�� 
			h->val.subList.tail = NULL;		//��ֵ��ָ��	 
	}
	return h;		// ���ش���������ͷָ�� 
} 


// ��������
int GListDepth(GLNode *h){
	int max,dep;
	GLNode *pre;
	
	if(h == NULL) return 1;		//�ݹ���� �ձ����Ϊ1
	if(h->tag == 0) return 0;	//�ݹ���� ԭ��Ԫ�����Ϊ 0
	
	// �ݹ����������
	pre = h;
	// ����� �ɷ�Ϊ ��ͷ�ͱ�β �Ա�β��ѭ��
	for(max = 0;pre != NULL;pre = pre->val.subList.tail)
	{
		dep = GListDepth(pre->val.subList.head);	//�ݹ����ͷ���
		if(dep > max) max = dep;	// �ڹ�����һ����Ѱ�����ֵ 
	 }
	 return max +1;	//��ǰ���+1 
} 

// ����� ����
int GListLength(GLNode *h){
	// ���� ���������  ͷָ��Ϊh
	int number = 0;
	GLNode *p;
	for(p = h;p != NULL; p = p->val.subList.tail)
	 	number ++;
	return number;
		
} 

// ����� ԭ��Ԫ�ظ���
int GListAtomNum(GLNode *h){
	// ���� ����� h ��ԭ��Ԫ�ظ���  h Ϊ ������ͷָ��
	if(h == NULL) return 0;
	else{
		if(h->tag == 0) return 1;
		else{
			return GListAtomNum(h->val.subList.head) + GListAtomNum(h->val.subList.tail);
		}
	} 
}

// ����ԭ��Ԫ��
GLNode *GListSearch(GLNode *h,DataType x){
	GLNode *p;
	if(h == NULL) return NULL;	//����ʧ�ܵݹ���� 
	if(h->tag ==0 && h->val.atom == x) return h;	//���ҳɹ��ݹ���� 
	if(h->tag ==1 && h->val.subList.head !=NULL){
		p = GListSearch(h->val.subList.head,x);		//��ͷ���в���
		if(p!=NULL) return p; 
	} 
	if(h->tag ==1 && h->val.subList.tail != NULL){
		p = GListSearch(h->val.subList.tail,x);		//��β���в���
		if(p != NULL) return p; 
	}
	return NULL;		//���ݵ���һ�� 
} 

// ���������
void DestroyGlist(GLNode *h){
	if(h == NULL) return ;
	if(h->tag == 1 && h->val.subList.head != NULL)	//����head��ָ�ӱ� 
		DestroyGlist(h->val.subList.tail);
	if(h->tag == 1 && h->val.subList.tail != NULL)
		DestroyGlist(h->val.subList.head);
	free(h);	//ɾ����ǰ�ڵ� 
} 
