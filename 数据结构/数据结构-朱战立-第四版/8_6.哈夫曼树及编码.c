#include<stdio.h>
#include<stdlib.h>

#define MaxValue 10000		//初始化权值最大值
#define MaxBit 4			//初始化最大编码位数
#define MaxN  10 			//初始 最大 节点数
#include "Haffman.h"

main(){
	int i,j,n=4;
	int weight[] = {1,3,5,7};
	HaffNode *myHaffTree = (HaffNode *)malloc(sizeof(HaffNode)*(2*n-1));
	Code *myHaffCode = (Code *)malloc(sizeof(Code)*n);
	
	if(n > MaxN)
	{
		printf("给出的n越界  修改MaxN\n");
		exit(1);
	 } 
	Haffman(weight,n,myHaffTree);
	HaffmanCode(myHaffTree,n,myHaffCode);
	
	// 输出 每个叶节点 的哈夫曼编码
	for(i=0;i<n;i++){
		printf("weight = %d  code = ",myHaffCode[i].weight);
		for(j = myHaffCode[i].start;j<n;j++)
			printf("%d",myHaffCode[i].bit[j]);
		printf("\n");
	} 
} 
