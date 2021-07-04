#include<stdio.h>
#include<stdbool.h>

//判断是否为素数，是则返回true，不是返回false
bool IsPrime(int val)
{
    int i;
    for(i=2; i<val; ++i)
    {
        if(val%i == 0)
        break;
    }
    if(i == val)
    return true;
    else
    return false;
}


int main(void)
{
    int m;
    scanf("%d",&m);

    if(IsPrime(m))
        printf("YES!\n");
    else
        printf("NO!\n");
}