#include<stdio.h>
#include<string.h>
#define MAX 1000005
//首先判断素数，是素数则no
//再用 “快速幂运算” O(n) = T(logn) 
typedef long long LL;
int num[MAX],n;
void select()
{
    int i,j;
    for(i=2;i<=MAX;i++)
    {
        for(j=i*2;j<=MAX;j+=i)
        {
            num[j]=1;
        }
    }
}
LL quick_pow(LL x,LL c)
{
    LL re=1;
    while(c>0)
    {
        if(c&1)
          re=re*x%n;
        x=x*x%n;
        c=c>>1;
    }
    return re;
}
int main()
{
    select();
    while(~scanf("%d",&n))
    {
        int i,flag=1;
        if(num[n]==0)
            printf("NO\n");
        else
        {
            for(i=2;i<n;i++)
            {
                if(quick_pow(i,n)!=i%n)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}

