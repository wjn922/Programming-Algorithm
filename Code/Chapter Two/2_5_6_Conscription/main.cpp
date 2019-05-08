#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
const int maxn=22000;
 
int n1,n2,n,m;
 
struct Edge
{
    int u,v,w;
}edge[maxn*3];
 
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
 
int fa[maxn];
 
int Find(int x)
{
    if(x==fa[x]) return x;
    else return fa[x]=Find(fa[x]);
}
 
int kruscal()
{
    int ans=0;
    sort(edge,edge+m,cmp);
    for(int i=0;i<n;i++) fa[i]=i;
    for(int i=0;i<m;i++)
    {
        int f1=Find(edge[i].u);
        int f2=Find(edge[i].v);
 
        if(f1==f2) continue;
 
        fa[f1]=f2;
        ans+=edge[i].w;
    }
    return ans;
}
 
int main()
{
    int T_T;
    scanf("%d",&T_T);
while(T_T--)
{
    scanf("%d%d%d",&n1,&n2,&m);
    n=n1+n2;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edge[i]=(Edge){a,b+n1,-c};
    }
    printf("%d\n",n*10000+kruscal());
}
    return 0;
}

