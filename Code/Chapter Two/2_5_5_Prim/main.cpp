#include <iostream>
#include<algorithm>
#include <cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//������dijkstra 
//O(V^2)

 
#define INF 10000
const int MAXN = 10000;
int dis[MAXN][MAXN];
int mincost[MAXN];			//���Ӽ���X�����ıߵ����������С���� 
int vis[MAXN];
int V;

int prim()
{
	fill(mincost, mincost+V, INF);
	fill(vis,vis+V,0);
	mincost[0] = 0;	//�Ӷ���0��ʼ
	
	int res;	//��С��
	
	while(1)
	{
		int u = -1;
		for(int v = 0; v<V; v++)
		{
			if(!vis[v] && (u==-1||mincost[v]<mincost[u]))
				u = v;	
		}	
		
		if(u==-1)	break;
		
		//����
		vis[u] = 1;
		res += mincost[u];
		for(int v = 0; v < V; v++)
		{
			mincost[v] = min(mincost[v], dis[u][v]);
		} 
	}	
}

int main(int argc, char** argv) {
	return 0;
}
