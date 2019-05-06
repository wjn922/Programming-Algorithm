#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//O(V^2) 
#define INF 10000
const int MAXN = 10000;
int dis[MAXN][MAXN];
int d[MAXN];		//原点到各点最短距离

int prev[MAXV];		//最短路径 前驱顶点 

int vis[MAXN];	//是否使用过
int V;

void dijkstra(int s)
{
	fill(d, d+V, INF);
	fill(vis, vis+V, false);
	fill(prev, path+V, -1); 
	d[s] = 0;
	
	while(1)
	{
		int u = -1;
		//遍历所有顶点，找出未使用过的中 d[i]最小的点
		for(int v = 0; v < V; v++)	 
		{
			if(!vis[v] && (u==-1 || d[v]<d[u]))
				u = v;
		}
		
		if(u==-1)	break;		//全部更新完
		
		//更新最短路径 
		vis[u] = 1;
		for(int v = 0; v < V; v++)
		{
			if(d[v]> d[u] + dis[u][v])
			{
				d[v] = d[u] + dis[u][v]);
				prev[v] = u;
			}
			
		} 
	}
}

vector<int> getPath(int t)
{
	vector<int> path;
	for(; t!=-1; t = prev[t])
		path.push_back(t);
		
	reverse(path.begin(), path.end());
	return path;
}

int main(int argc, char** argv) {
	return 0;
}
