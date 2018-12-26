#include<stdio.h>
#include<stdlib.h>

//  迷宫问题  回溯算法

typedef struct{
	// 路口的结构体定义  左中 右 
	int left;	
	int forward;
	int right; 
}InterSection;

typedef struct {
	// 迷宫结构体定义
	int mazeSize;	//路口个数
	InterSection *intSec;	//路口集合
	int Exit;		//出口 
}Maze;


// 解迷宫 
int TravMaze(Maze *m,int currSetValue){
	// 用回溯算法 遍历所有分支 curr为 当前路口
	if(currSetValue > 0){
		if(currSetValue == m->Exit)		//递归出口
		{
			printf("%d  <==",currSetValue);
			return 1; 
		} 
		else if(TravMaze(m,m->intSec[currSetValue].forward) == 1)	//向前 
		{
			printf("%d  <==",currSetValue);
			return 1; 
		} 
		else if(TravMaze(m,m->intSec[currSetValue].right) == 1)	//向右 
		{
			printf("%d  <==",currSetValue);
			return 1; 
		} 
		else if(TravMaze(m,m->intSec[currSetValue].left) == 1)	//向左
		{
			printf("%d  <==",currSetValue);
			return 1; 
		} 
	} 
	return 0;		//表示此节点不通   
}

// 制造迷宫
int CreatMaze(char *filename,Maze *m){
	// 读取 filename 文件中的数据构建迷宫
	FILE *fp;
	int i;
	fp = fopen(filename,"r");	//打开文件
	if(!fp){
		printf("数据文件无法打开!\n");
		return ;
	} 
	
	fscanf(fp,"%d",&m->mazeSize);		//读入路口数量
	
	// 建立 mazeSize+1个元素的数组
	m->intSec = (InterSection*)malloc(sizeof(InterSection)*(m->mazeSize+1));
	
	for(i =1;i<=m->mazeSize;i++){
			fscanf(fp,"%d%d%d",&m->intSec[i].left,&m->intSec[i].forward,&m->intSec[i].right);	//路口信息 
	}
	fscanf(fp,"%d",&m->Exit);	//出口 
	fclose(fp); 	
} 


main(){
	Maze m;
	int start = 1;
	
	CreatMaze("Maze1.dat",&m);
	if(TravMaze(&m,start))
		printf("\n 此迷宫的一条通路如上所示!");
	else
		printf("\n 此迷宫无解!"); 
}
