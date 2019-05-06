#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue> 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//���dijkstra ��ζ�·
//������v�Ĵζ�· 1. ����������u�����·+u->v  2.����������u�Ĵζ�·+u->v

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

typedef pair<int, int> P;  //first����ʼ�㵽�õ���̾��룬second�Ǹõ���

int dist[MAXN];		//��̾��� 
int dist2[MAXN];	//�ζ̾���

void solve()
{
	//��ʼ��������ʼ����������ȶ��� 
	priority_queue<P, vector<P>, greater<P> > que;
	fill(dist, dist+N, INF);
	fill(dist, dist2+N, INF);
	dist[0] = 0;
	que.push(P(0, 0));	
	
	while(!que.empty())
	{
		//ȡ����ͷ
		P p = que.top();
		que.pop();
		int v = p.second;
		int d = p.first;
		
		if(dist2[v] < d)	continue;	//����������㵽��ʼ���������иö����� ����ʼ�����Ĵζ̾��뻹Զ������ 
		
		//����·�� 
		for(int i = 0; i < G[v].size(); i++)
		{
			edge &e = G[v][i];		//�������ô���
			
			//�ζ�·�����ֿ��� 
			int d2 = d + e.cost;	//ע������ ������dist[e.from]+e.cost 
			if(dist[e.to] > d2)		//d2�����·
			{	
				swap(dist[e.to], d2);
				que.push(P(dist[e.to], e.to));
			} 
			if(dist2[e.to] > d2 && dist[e.to] < d2) //d2�Ǵζ�·
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
