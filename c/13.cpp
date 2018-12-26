#include<stdio.h>
main()
{
	int a,b,c,s,n,i;
	int xh(int x);
	scanf("%d,%d,%d",&a,&b,&c);
	a=xh(a);
	b=xh(b);
	c=xh(c);
	s=a+b+c;
	printf("Êä³öa£¬b£¬cµÄ½×³Ë  %d",s);

 } 
 
 
 int xh(int x)
 {
 	int i,n=1;
 	for(i=1;i<=x;i++)
 	n=n*i;
 	return (n);
 }
