#include<stdio.h>
#include<string.h>

// ����:  ���Ѿ�ƥ����ַ����� ����ǰ׺ƥ���λ�� ƥ�䴮���� 

//ƥ�䴮Խ���غ�, ʧ��ʱ �����ƶ��Ĳ���Խ��
//ǰ��׺ ��ʾǰ׺Ӧ���ƶ�����׺��λ�ý��ж���ƥ�� 
//��Ϊ ǰ��׺�������ͬʱ �ƶ�6����Ԫ�� ����ȡ��ʱ���ȡ��ǰһ��Ԫ�ص�next 
void makeNext(const char P[],int next[])
{
	int q,k;
	int m = strlen(P);
	next[0] = 0;
	for(q=1;k=0,q<m;++q)
	{
		while(k>0 && P[q] != P[k])	//����: next�������������ظ��Ӵ��ַ����ĸ��� 
			k = next[k-1];
		
		if(P[q] == P[k])
			k++;
		
		next[q] = k;
	}
 } 


int kmp(const char T[],const char P[],int next[])
{
	int n,m;
	int i,q;
	n = strlen(T);
	m = strlen(P);
	
	makeNext(P,next);					//����next�� 
	for (i =0,q=0;i<n;++i)
	{
		while(q>0&&P[q] != T[i])		//ƥ�䲻�� ����next������ƶ� 
			q = next[q-1];
		
		if(P[q] == T[i])		//ƥ������ �������ƥ�� 
			q++;
		
		if(q==m)			//���ƥ�� 
			printf("finded it %d\n",i-m+1); 
	}
}

main(){
	int next[10] = {0};
    char T[] = "ababxbababcdabdfdsss";
    char P[] = "abcdabd";
    
    printf("%s\n",T);
    printf("%s\n",P );
    
    kmp(T,P,next); 
    
} 
