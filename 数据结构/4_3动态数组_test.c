#include<stdio.h>
#include<malloc.h>
#include<string.h>

#include "DString.h"

main(){
	DString s1,s2,s3;
	int i,max1 =5,max2 = 9,max3 = 0;
	
	// test 
	Initate(&s1,max1,"Data");
	Initate(&s2,max2,"Structure");
	Initate(&s3,max3,"");
	
	printf("s2:    ");
	for (i=0;i<s2.length;i++)
		printf("%c",s2.str[i]);
	printf("\n maxlen: %d",s2.maxLength);
	printf("\n len: %d\n",s2.length);
	
	
	//test2
	Insert(&s2,0,s1);
	printf(" s2 : ");
	for (i=0;i<s2.length;i++)
		printf("%c",s2.str[i]);
	printf("\nmaxlen: %d\n",s2.maxLength);
	printf("len: %d\n",s2.length);
	
	
	//test3
	Delete(&s2,0,4);
	printf(" s2 : ");
	for (i=0;i<s2.length;i++)
		printf("%c",s2.str[i]);
	printf("\nmaxlen: %d\n",s2.maxLength);
	printf("len: %d\n",s2.length);
	
	//test4
	SubString(&s2,0,5,&s3);
	printf(" s3 : ");
	for (i=0;i<s3.length;i++)
		printf("%c",s3.str[i]);
	printf("\nmaxlen: %d\n",s3.maxLength);
	printf("len: %d\n",s3.length);
}
