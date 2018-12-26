#define ok 1
#define error 0
#define ture 1
#define false 0
#define MAXSIZE 20 

typedef int status;

Status GetElem(SqList L,int i,ElemType *e)	//拿到 数据位置 
{
	if(L.length==0||i<1||i>L.length)
	{
		return error;
	}
	*e = L.data[i-1];
	
	return ok;
 }
 
Status ListInsert(SqList *L,int i, ElemType e)
{
	int k;
	if(L->length==MAXSIZE)  //顺序表已满
	{
		return error;
	}
	if(i<1||i>L->length+1)	//当i不在范围时
	{
		return error;
		 }	 
		 
	if(i<=L->length)
	{	//插入位置数据元素向后移动一位 
		for(k=L->length-1;k>=i-1;k--)
		{
			L->data[k+1]=L->data[k];
		}
	}
	
	L->data[i-1]=e;	//新元素插入 
	L->length++;
	
	return ok; 
 } 
