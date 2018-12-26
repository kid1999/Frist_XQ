#include<stdio.h>
#include<stdlib.h>

#define MaxValue 10000		//��ʼ��Ȩֵ���ֵ
#define MaxBit 4			//��ʼ��������λ��
#define MaxN  10 			//��ʼ ��� �ڵ���
#include "Haffman.h"

main(){
	int i,j,n=4;
	int weight[] = {1,3,5,7};
	HaffNode *myHaffTree = (HaffNode *)malloc(sizeof(HaffNode)*(2*n-1));
	Code *myHaffCode = (Code *)malloc(sizeof(Code)*n);
	
	if(n > MaxN)
	{
		printf("������nԽ��  �޸�MaxN\n");
		exit(1);
	 } 
	Haffman(weight,n,myHaffTree);
	HaffmanCode(myHaffTree,n,myHaffCode);
	
	// ��� ÿ��Ҷ�ڵ� �Ĺ���������
	for(i=0;i<n;i++){
		printf("weight = %d  code = ",myHaffCode[i].weight);
		for(j = myHaffCode[i].start;j<n;j++)
			printf("%d",myHaffCode[i].bit[j]);
		printf("\n");
	} 
} 
