
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

main()
{
	char name [100];
	char *description;
	
	strcpy(name,"Jack simith");
	
	//动态分配内存
//	一 
//	description = (char *)malloc(200 * sizeof(char));
//	二
	description =  (char *)calloc(200,sizeof(char));
	
	if(description ==NULL){
		fprintf(stderr,"Error  no memory! \n");
	} 
	 else{
	 	strcpy(description,"Jack is a good boy ,e very liske study");
	 	
	 }
	 printf("name: %s \n",name);
	 printf("description: %s",description);
 } 
