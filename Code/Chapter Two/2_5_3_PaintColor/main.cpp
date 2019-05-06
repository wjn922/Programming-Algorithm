//����ͼ�ж� �� dfs 
#include <iostream>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int MAXN = 100000;
vector<int> G[MAXN];
int V, E;		//����ͱߵ����� 
int color[MAXN];	//��¼���������ɫ�� 1 or -1 
//int vis[MAXN] = {0};	//��¼�Ƿ񾭹��� 
//int flag = 0;		//����Ƿ���� 

int sum(int a[], int n)
{
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans += a[i];
	return ans;
}

bool dfs(int vnum, int c)	//���㣬��ɫ 
{	
	color[vnum] = c;	
	for(int i = 0; i < G[vnum].size(); i++)		//��������vnum���������ӵ� 
	{
		if(c == color[G[vnum][i]])		//�Ѿ����������ڶ��㣬����ɫ��ͬ 
			return false;
		if(color[G[vnum][i]]==0 && !dfs(G[vnum][i], -c))	//δ���������ڶ��� 	
			return false;
	}
	return true;//���ж������������������ 
}

int main(int argc, char** argv) {
	cin >> V >> E; 
	for(int i = 0; i < E; i++)
	{
		int s, e;	//�ߵ���������
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
