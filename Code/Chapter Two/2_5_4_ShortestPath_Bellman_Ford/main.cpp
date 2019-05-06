#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Bellman-Ford -> SPFA
//T(n) = 0(V*E) 
#define INF 100000
const int MAXN = 100000;
struct edge
{
	int start, end, cost;
}edges[MAXN];

int d[MAXN];	//Shortest Distance
int V, E; 

int flag = 0;	//判断是否有负圈
 
void shortestpath(int s)
{
	for(int i = 0; i < V; i++)
		d[i] = INF;
	d[s] = 0;
	int count = 0; 
	
	while(1)
	{
		//若无负圈，则while循环V-1次 
		count++;
		
		bool update = false;
		for(int i = 0; i < E; i++)
		{
			edge e = edges[i];
			if(d[e.start]!=INF && d[e.end]>d[e.start]+e.cost)
			{
				d[e.end]=d[e.start]+e.cost;
				update = true;
			}
		}
		
		if(!update)	break;	//有负圈 
		if(count == V)	
		{
			flag = 1; 
		}
	}
}

int main(int argc, char** argv) {
	return 0;
}
