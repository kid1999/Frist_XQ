typedef struct {
	char *str;
	int maxLength;
	int length;
}DString;

//初始化 
void Initate(DString *s,int max,char *string){
	int i;
	s->str = (char*)malloc(sizeof(char)*max);	//申请动态内存
	s->maxLength = max;					//最大元素个数 
	s->length = strlen(string); 		// 当前串长度
	for(i=0;i<s->length;i++){
		s->str[i] = string[i];		// 赋值 
	} 
} 

// 插入子串
int Insert(DString *s,int pos,DString T){
	// 在pos处 插入 T
	int i;
	if(pos < 0)
	{
		printf("参数pos出错\n");
		return 0;
	 } 
	 else{
	 	if(s->length + T.length > s->maxLength){
	 		// 重新申请s->str所指空间
			 realloc(s->str,(s->length + T.length)*sizeof(char));
			 s->maxLength = s->length + T.length; 
		 }
		 for (i=s->length-1;i>=pos;i--)
		 	s->str[i+T.length]  = s->str[i];	// 依次后移 T.length个位置
		
		for(i=0;i<T.length;i++)
			s->str[pos+i] = T.str[i];	 //插入
		s->length += T.length;	//置新的元素个数
		return 1; 
	 }
} 

// 删除子串
int Delete(DString *s,int pos,int len){
	// 删除S 从pos开始 长度为len的子串
	int i;
	if(s->length <= 0){
		printf("数组中为未存放字符\n");
		return 0;
	} 
	else if(pos <0 ||len <0 ||pos+len >s->length){
		printf("参数pos和len不合法\n");
		return 0; 
	}
	else{
		for (i=pos+len;i<=s->length-1;i++)
			s->str[i-len] = s->str[i];	//依次前移len个位置
		s->length = s->length -len;
		return 1; 
	}
} 

// 取子串 
int SubString(DString *s,int pos,int len,DString *t){
	// 取S 从 pos位置开始len的子串
	int i;
	if(pos<0 || len < 0|| pos+len>s->length)
	{
		printf("参数pos和len出错\n");
		return 0; 
	}
	if(len > t->maxLength){
		t->str = (char*)malloc(len*sizeof(char));	//重新申请数组空间
		t->maxLength = len; 
	}  
	for (i=0;i<len;i++)
		t->str[i] = s->str[pos+i];
	t->length = len;
	return 1;
	
} 

// 撤销 
void Destroy(DString *s){
	free(s->str);
	s->maxLength = 0;
	s->length = 0; 
}
