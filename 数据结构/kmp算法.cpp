#include<stdio.h>
#include<string.h>

// 核心:  在已经匹配的字符串中 找与前缀匹配的位置 匹配串往左 

//匹配串越少重合, 失配时 可以移动的步伐越大
//前后缀 表示前缀应该移动到后缀的位置进行二次匹配 
//因为 前后缀有五个相同时 移动6个单元格 所以取的时候就取得前一个元素的next 
void makeNext(const char P[],int next[])
{
	int q,k;
	int m = strlen(P);
	next[0] = 0;
	for(q=1;k=0,q<m;++q)
	{
		while(k>0 && P[q] != P[k])	//核心: next数组里面就是最长重复子串字符串的个数 
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
	
	makeNext(P,next);					//产生next表 
	for (i =0,q=0;i<n;++i)
	{
		while(q>0&&P[q] != T[i])		//匹配不上 按照next表进行移动 
			q = next[q-1];
		
		if(P[q] == T[i])		//匹配上了 往后继续匹配 
			q++;
		
		if(q==m)			//完成匹配 
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
