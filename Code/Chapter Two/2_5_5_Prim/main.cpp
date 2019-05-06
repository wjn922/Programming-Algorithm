#include <iostream>
#include<algorithm>
#include <cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//类似于dijkstra 
//O(V^2)

 
#define INF 10000
const int MAXN = 10000;
int dis[MAXN][MAXN];
int mincost[MAXN];			//到从集合X出发的边到各顶点的最小距离 
int vis[MAXN];
int V;

int prim()
{
	fill(mincost, mincost+V, INF);
	fill(vis,vis+V,0);
	mincost[0] = 0;	//从顶点0开始
	
	int res;	//最小数
	
	while(1)
	{
		int u = -1;
		for(int v = 0; v<V; v++)
		{
			if(!vis[v] && (u==-1||mincost[v]<mincost[u]))
				u = v;	
		}	
		
		if(u==-1)	break;
		
		//更新
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
