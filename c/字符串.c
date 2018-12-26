#include<stdio.h>
#include<string.h>
main() {
	char str[] = "hello world";
	char str2[] = " and java or python";
	char str1[20];
	int i = 10;
	printf("%s \n",str);
	
	//copy
	strcpy(str1,str);
	printf("%s \n",str1);
	
	//strlen
	printf("%d \n",strlen(str));
	
	//strcat
	printf("%s \n",strcat(str,str2));
	
	//strcmp
	printf("%d \n",strcmp(str,str1));
	
	//strchr
	printf("%x \n",strchr(str,'w'));

}
