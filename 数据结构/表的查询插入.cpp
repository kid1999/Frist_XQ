#define ok 1
#define error 0
#define ture 1
#define false 0
#define MAXSIZE 20 

typedef int status;

Status GetElem(SqList L,int i,ElemType *e)	//�õ� ����λ�� 
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
	if(L->length==MAXSIZE)  //˳�������
	{
		return error;
	}
	if(i<1||i>L->length+1)	//��i���ڷ�Χʱ
	{
		return error;
		 }	 
		 
	if(i<=L->length)
	{	//����λ������Ԫ������ƶ�һλ 
		for(k=L->length-1;k>=i-1;k--)
		{
			L->data[k+1]=L->data[k];
		}
	}
	
	L->data[i-1]=e;	//��Ԫ�ز��� 
	L->length++;
	
	return ok; 
 } 
