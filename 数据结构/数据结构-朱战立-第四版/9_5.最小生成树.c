#include<stdio.h>
#include<malloc.h>

typedef char DataType;		//顺序表数据类型 
typedef char VerT;			//顶点数据类型 
#define MaxSize 10			//顺序表数组最大值 
#define MaxVertices 10 		//顶点最大个数
#define MaxWeight  10000	//权值具体最大值

#include "AdjMGraph.h"
#include "AdjMGraphCrate.h"
#include "Prim.h"

main()
{
	AdjMGraph g;
	char a[] = {'A','B','C','D','E','F','G'};
	RowColWeight rcw[] = {{0,1,50},{1,0,50},{0,2,60},{2,0,60},{1,3,65},{3,1,65},{1,4,40},{4,1,40},{2,3,52},{3,2,52},{2,6,45},{6,2,45},{3,4,50},
	{4,3,50},{3,5,30},{5,3,30},{3,6,42},{6,3,42},{4,5,70},{5,4,70}};
	
	int n = 7,e=20,i;		// 7顶点 20边
	MinSpanTree closeVertex[7];			//定义保存最小生成树的数组
	
	CreatGraph(&g,a,n,rcw,e);		//创建图
	Pirm(g,closeVertex);		//调用 普利姆算法
	
	//输出最小生成树的顶点序号 和权值序列
	printf("初始顶点: %c\n",closeVertex[0].vertex);
//	for(i=1;i<n;i++)
//		printf("顶点: %c  边的权值: %d\n",closeVertex[i].vertex,closeVertex[i].weight); 

		printf("%c  ",closeVertex[3]);
 } 
