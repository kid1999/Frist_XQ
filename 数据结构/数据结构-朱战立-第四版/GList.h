//  广义表  链式存储

typedef struct GListNode{
	int tag;
	union{
		DataType atom;	//原子元素域
		struct{
			struct GListNode *head;	//头指针 
			struct GListNode *tail;	//尾指针 
		}subList;	// 子表域 
	}val;
}GLNode;

// 创建广义表 
void DecomposeStr(char str[],char hstr[]){
	// 把 表示广义表的字符串 分解成 头字符串hstr 和 表尾字符串str
	int i,j,tag,n = strlen(str);
	char ch;
	
	ch = str[0];
	tag = 0;
	for(i=0;i<=n-1;i++){
		if(str[i] == ',' && tag == 1)	//搜索最外层的第一个逗号 
			break;
		ch = str[i];
		if(ch == '(') tag++;
		if(ch == ')') tag--;
	} 
	if(i <= n-1 && str[i] == ',')  // 广义表表尾 非空时
		{
			for(j=0;j<i-1;j++)	//取表头字符串 
				hstr[j] = str[j+1];
			
			hstr[j] = '\0';		//添加结束符
			
			if(str[i] == ',') i++;
			
			str[0] = '(';
			
			for(j=1;i<=n-2;i++,j++)		//	取表尾字符串 
				str[j] = str[i];
			
			str[j] = ')';
			str[++j] = '\0';
		 } 
	else{
		str++;		// 跳过最左边的(
		strncpy(hstr,str,n-2);  //不复制最右边的)
		hstr[n-2] = '\0';
		str--; 	// 恢复指针位置
		strcpy(str,"()");	//表尾为空 
	}
} 

GLNode* CreatGList(char str[]){
	// 按照广义表字符串 创建广义表  返回广义表的头指针
	// str 为表示广义表的 字符串
	GLNode *h;
	char hstr[200];
	int len = strlen(str);
	if(strcmp(str,"()") == 0) h = NULL;
	else if(len == 1) 	// 建立 原子元素节点
	{
		h = (GLNode *)malloc(sizeof(GLNode));
		h->tag = 0;
		h->val.atom = str[0];
		
	} 
	else{
		// 建立 子表
		h = (GLNode *)malloc(sizeof(GLNode));
		h->tag = 1;
		
		//把字符串 分解为 hster 和 str
		DecomposeStr(str,hstr);
		h->val.subList.head = CreatGList(str);	// 创建表头的广义表
		if(strcmp(str,"()") !=0)	//表尾非空时 
			h->val.subList.tail = CreatGList(str);	//创建表尾的广义表
		else	//	表尾为空 
			h->val.subList.tail = NULL;		//赋值空指针	 
	}
	return h;		// 返回创建广义表的头指针 
} 


// 广义表深度
int GListDepth(GLNode *h){
	int max,dep;
	GLNode *pre;
	
	if(h == NULL) return 1;		//递归出口 空表深度为1
	if(h->tag == 0) return 0;	//递归出口 原子元素深度为 0
	
	// 递归求广义表深度
	pre = h;
	// 广义表 可分为 表头和表尾 对表尾链循环
	for(max = 0;pre != NULL;pre = pre->val.subList.tail)
	{
		dep = GListDepth(pre->val.subList.head);	//递归求表头深度
		if(dep > max) max = dep;	// 在广义表的一层中寻找最大值 
	 }
	 return max +1;	//当前深度+1 
} 

// 广义表 长度
int GListLength(GLNode *h){
	// 返回 广义表的深度  头指针为h
	int number = 0;
	GLNode *p;
	for(p = h;p != NULL; p = p->val.subList.tail)
	 	number ++;
	return number;
		
} 

// 广义表 原子元素个数
int GListAtomNum(GLNode *h){
	// 返回 广义表 h 的原子元素个数  h 为 广义表的头指针
	if(h == NULL) return 0;
	else{
		if(h->tag == 0) return 1;
		else{
			return GListAtomNum(h->val.subList.head) + GListAtomNum(h->val.subList.tail);
		}
	} 
}

// 查找原子元素
GLNode *GListSearch(GLNode *h,DataType x){
	GLNode *p;
	if(h == NULL) return NULL;	//查找失败递归出口 
	if(h->tag ==0 && h->val.atom == x) return h;	//查找成功递归出口 
	if(h->tag ==1 && h->val.subList.head !=NULL){
		p = GListSearch(h->val.subList.head,x);		//在头链中查找
		if(p!=NULL) return p; 
	} 
	if(h->tag ==1 && h->val.subList.tail != NULL){
		p = GListSearch(h->val.subList.tail,x);		//在尾链中查找
		if(p != NULL) return p; 
	}
	return NULL;		//回溯到上一层 
} 

// 撤销广义表
void DestroyGlist(GLNode *h){
	if(h == NULL) return ;
	if(h->tag == 1 && h->val.subList.head != NULL)	//撤销head所指子表 
		DestroyGlist(h->val.subList.tail);
	if(h->tag == 1 && h->val.subList.tail != NULL)
		DestroyGlist(h->val.subList.head);
	free(h);	//删除当前节点 
} 
