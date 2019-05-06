#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue> 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//借鉴dijkstra 求次短路
//到顶点v的次短路 1. 到其他顶点u的最短路+u->v  2.到其他顶点u的次短路+u->v

#define INF 10000
const int MAXN = 10000; 
int N, R;
struct edge
{
	int from, to, cost;
	edge(int start, int end, int len)
	{
		from = start; to = end; cost = len;
	}
};
vector<edge> G[MAXN];

typedef pair<int, int> P;  //first是起始点到该点最短距离，second是该点编号

int dist[MAXN];		//最短距离 
int dist2[MAXN];	//次短距离

void solve()
{
	//初始化，将起始点添加入优先队列 
	priority_queue<P, vector<P>, greater<P> > que;
	fill(dist, dist+N, INF);
	fill(dist, dist2+N, INF);
	dist[0] = 0;
	que.push(P(0, 0));	
	
	while(!que.empty())
	{
		//取出队头
		P p = que.top();
		que.pop();
		int v = p.second;
		int d = p.first;
		
		if(dist2[v] < d)	continue;	//弹出这个顶点到起始点距离比所有该顶点中 到起始点距离的次短距离还远，跳过 
		
		//更新路径 
		for(int i = 0; i < G[v].size(); i++)
		{
			edge &e = G[v][i];		//采用引用传递
			
			//次短路的两种可能 
			int d2 = d + e.cost;	//注意这里 不是用dist[e.from]+e.cost 
			if(dist[e.to] > d2)		//d2是最短路
			{	
				swap(dist[e.to], d2);
				que.push(P(dist[e.to], e.to));
			} 
			if(dist2[e.to] > d2 && dist[e.to] < d2) //d2是次短路
			{
				swap(dist2[e.to], d2);
				que.push(P(dist2[e.to], e.to)) ;
			}
	
		} 
	} 
} 

 
 
int main(int argc, char** argv) {
	cin >> N >> R;
	int start, end, len;
	for(int i = 0; i < R; i++)
	{
		cin >> start >> end >> len;
		G[start-1].push_back(edge(start-1, end-1, len)); 
		G[end-1].push_back(edge(end-1, start-1, len)); 
	}
	
	solve();
	cout << dist2[N-1];
	return 0;
}
