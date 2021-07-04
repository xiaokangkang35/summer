//求组合数Cmn

#include<stdio.h>
int fac(int n);
int Cmn(int m,int n);
void main()
{
    int m;
    int n;
    int sum;
    printf("m=");
    scanf("%d",&m);
    printf("n=");
    scanf("%d",&n);
    sum=Cmn(m,n);
    printf("Cmn=%d",sum);
}

int fac(int n)
{
    int f=1;
    int i;
    for(i=1;i<=n;i++)
    f=f*i;
    return f;
}
int Cmn(int m,int n)
{
    int f=1;
    f=fac(n)/(fac(m)*fac(n-m));
    return f;
}