#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
1. d[i] <= d[i+1]	i+1 -> i 0
2. d[AL]+DL >= d[BL]  AL->BL  DL
3. d[AD]+DD<=d[BD]   BD->AD  -DD
满足这三个不等式的 令d(v)-d(s)的最大值 为s到v的最短距离 
线性规划, 这里可以采用图论;
因为有负边，用bellman
*/
#define INF 10000

const int MAXN = 1000;
const int MAX_ML = 10000;
const int MAX_MD = 10000;
//const long long MAX_DL = 1000000;
//const long long MAX_DD = 1000000;

int N, ML, MD;
int AL[MAX_ML], BL[MAX_ML], DL[MAX_ML];
int AD[MAX_MD], BD[MAX_MD], DD[MAX_MD];

int d[MAXN];		//最短距离
int res;

//因为有负权，采用BELLMAN
void solve()
{
	fill(d, d+N, INF);
	d[0] = 0;
	
	// O(n) = (V * E)
	for(int k = 0; k < N; k++)
	{
		//1.  i+1->i 0
		for(int i = 0; i < N-1; i++)
		{
			if(d[i+1] < INF);
				d[i] = min(d[i], d[i+1]);
		}
		
		//2. AL->BL  DL
		for(int i = 0; i < ML; i++)
		{
			if(d[AL[i]-1] < INF)
				d[BL[i]-1] = min(d[BL[i]-1], d[AL[i]-1] + DL[i]);
		}
		
		//3. BD->AD  -DD
		for(int i = 0; i < MD; i++)
		{
			if(d[BD[i]-1] < INF)
				d[AD[i]-1] = min(d[AD[i]-1], d[BD[i]-1] - DD[i]);
		}
		
	}
	
	res = d[N-1];
	
	
}
 

int main(int argc, char** argv) {
	cin >> N >> ML >> MD;
	for(int i = 0; i < ML; i++)
	{
		cin >> AL[i] >> BL[i] >> DL[i];
	}
	for(int i = 0; i < MD; i++)
	{
		cin >> AD[i] >> BD[i] >> DD[i];
	}
	 
	solve();
	if(d[0]<0)  //存在负圈，无解
		res = -1;
	else if (res == INF)
		res = -2;
	
	cout << res;
	return 0;
}
