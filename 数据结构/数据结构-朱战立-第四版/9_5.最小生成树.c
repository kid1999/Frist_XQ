#include<stdio.h>
#include<malloc.h>

typedef char DataType;		//˳����������� 
typedef char VerT;			//������������ 
#define MaxSize 10			//˳����������ֵ 
#define MaxVertices 10 		//����������
#define MaxWeight  10000	//Ȩֵ�������ֵ

#include "AdjMGraph.h"
#include "AdjMGraphCrate.h"
#include "Prim.h"

main()
{
	AdjMGraph g;
	char a[] = {'A','B','C','D','E','F','G'};
	RowColWeight rcw[] = {{0,1,50},{1,0,50},{0,2,60},{2,0,60},{1,3,65},{3,1,65},{1,4,40},{4,1,40},{2,3,52},{3,2,52},{2,6,45},{6,2,45},{3,4,50},
	{4,3,50},{3,5,30},{5,3,30},{3,6,42},{6,3,42},{4,5,70},{5,4,70}};
	
	int n = 7,e=20,i;		// 7���� 20��
	MinSpanTree closeVertex[7];			//���屣����С������������
	
	CreatGraph(&g,a,n,rcw,e);		//����ͼ
	Pirm(g,closeVertex);		//���� ����ķ�㷨
	
	//�����С�������Ķ������ ��Ȩֵ����
	printf("��ʼ����: %c\n",closeVertex[0].vertex);
//	for(i=1;i<n;i++)
//		printf("����: %c  �ߵ�Ȩֵ: %d\n",closeVertex[i].vertex,closeVertex[i].weight); 

		printf("%c  ",closeVertex[3]);
 } 
