#include <iostream>
#include <cmath>
#include <algorithm> 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//对背包问题进行优化，只用一维数组即可解决01背包及完全背包问题 

const int MAXN = 10000;
int N, W;
int w[MAXN+1], v[MAXN+1];
int dp1[MAXN+1];  	//01背包问题 
int dp2[MAXN+1];	//完全背包问题 

int main(int argc, char** argv) {
	cin >> N >> W;
	for(int i = 1; i <= N; i++)
		cin >> w[i];
	for(int i = 1; i <= N; i++)
		cin >> v[i];
	
	
	
	//01背包 
	for(int i = 1; i <= N; i++ )
	{
		for(int j= W; j >=1; j--) 
		{
			if(j >= w[i])
			{
				dp1[j] = max(dp1[j], dp1[j - w[i]] + v[i]);
			}
		}
	}
	
	//完全背包 
	for(int i = 1; i <= N; i++ )
	{
		for(int j = 1; j <= W; j++) 	//相比01背包最终优化代码，只是换了遍历方向而已
		{
			if(j >= w[i])
			{
				dp2[j] = max(dp2[j], dp2[j - w[i]] + v[i]);
			}
		}
	}
	
	cout << dp1[W] << endl;
	cout << dp2[W] << endl;
	return 0;
}
