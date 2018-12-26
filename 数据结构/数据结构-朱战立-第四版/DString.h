typedef struct {
	char *str;
	int maxLength;
	int length;
}DString;

//��ʼ�� 
void Initate(DString *s,int max,char *string){
	int i;
	s->str = (char*)malloc(sizeof(char)*max);	//���붯̬�ڴ�
	s->maxLength = max;					//���Ԫ�ظ��� 
	s->length = strlen(string); 		// ��ǰ������
	for(i=0;i<s->length;i++){
		s->str[i] = string[i];		// ��ֵ 
	} 
} 

// �����Ӵ�
int Insert(DString *s,int pos,DString T){
	// ��pos�� ���� T
	int i;
	if(pos < 0)
	{
		printf("����pos����\n");
		return 0;
	 } 
	 else{
	 	if(s->length + T.length > s->maxLength){
	 		// ��������s->str��ָ�ռ�
			 realloc(s->str,(s->length + T.length)*sizeof(char));
			 s->maxLength = s->length + T.length; 
		 }
		 for (i=s->length-1;i>=pos;i--)
		 	s->str[i+T.length]  = s->str[i];	// ���κ��� T.length��λ��
		
		for(i=0;i<T.length;i++)
			s->str[pos+i] = T.str[i];	 //����
		s->length += T.length;	//���µ�Ԫ�ظ���
		return 1; 
	 }
} 

// ɾ���Ӵ�
int Delete(DString *s,int pos,int len){
	// ɾ��S ��pos��ʼ ����Ϊlen���Ӵ�
	int i;
	if(s->length <= 0){
		printf("������Ϊδ����ַ�\n");
		return 0;
	} 
	else if(pos <0 ||len <0 ||pos+len >s->length){
		printf("����pos��len���Ϸ�\n");
		return 0; 
	}
	else{
		for (i=pos+len;i<=s->length-1;i++)
			s->str[i-len] = s->str[i];	//����ǰ��len��λ��
		s->length = s->length -len;
		return 1; 
	}
} 

// ȡ�Ӵ� 
int SubString(DString *s,int pos,int len,DString *t){
	// ȡS �� posλ�ÿ�ʼlen���Ӵ�
	int i;
	if(pos<0 || len < 0|| pos+len>s->length)
	{
		printf("����pos��len����\n");
		return 0; 
	}
	if(len > t->maxLength){
		t->str = (char*)malloc(len*sizeof(char));	//������������ռ�
		t->maxLength = len; 
	}  
	for (i=0;i<len;i++)
		t->str[i] = s->str[pos+i];
	t->length = len;
	return 1;
	
} 

// ���� 
void Destroy(DString *s){
	free(s->str);
	s->maxLength = 0;
	s->length = 0; 
}
