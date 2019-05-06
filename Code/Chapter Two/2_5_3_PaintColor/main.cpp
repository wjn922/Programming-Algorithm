//二分图判定 ， dfs 
#include <iostream>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int MAXN = 100000;
vector<int> G[MAXN];
int V, E;		//顶点和边的数量 
int color[MAXN];	//记录各个点的颜色， 1 or -1 
//int vis[MAXN] = {0};	//记录是否经过点 
//int flag = 0;		//标记是否可以 

int sum(int a[], int n)
{
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans += a[i];
	return ans;
}

bool dfs(int vnum, int c)	//顶点，颜色 
{	
	color[vnum] = c;	
	for(int i = 0; i < G[vnum].size(); i++)		//遍历顶点vnum的所有连接点 
	{
		if(c == color[G[vnum][i]])		//已经经过的相邻顶点，而颜色相同 
			return false;
		if(color[G[vnum][i]]==0 && !dfs(G[vnum][i], -c))	//未经过的相邻顶点 	
			return false;
	}
	return true;//所有顶点遍历过，符合条件 
}

int main(int argc, char** argv) {
	cin >> V >> E; 
	for(int i = 0; i < E; i++)
	{
		int s, e;	//边的两个顶点
		cin >> s >> e;
		G[s].push_back(e);
		G[e].push_back(s);
	}
	
	bool flag = dfs(0,1);
	if(flag)	
		cout << "yes";
	else
		cout << "no";
	
	
	
	return 0;
}
