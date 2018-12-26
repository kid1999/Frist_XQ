#include<stdio.h>
int max(in x,int y)
{
    return x>y?x:y;
}
main()
{   //º¯ÊıÖ¸Õë
    int (*p)(int,int) = & max;
    int a,b,c,d;
    scanf("%d,%d,%d",&a,&b,&c);
    d = p(p(a,b),c);
    printf("%d",d);
}
