//DP
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int MAXN = 1000;
int N, W;
int w[MAXN+1], v[MAXN+1];
int dp[MAXN+1][MAXN+1];

int main(int argc, char** argv) {
	cin >> N >> W;
	for(int i = 1; i <= N; i++)
		cin >> w[i];
	for(int i = 1; i <= N; i++)
		cin >> v[i];

	
	//dp
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= W; j++)
		{
			if(w[i] > j)		//重量比容量大，就不放
			{
				dp[i][j] = dp[i-1][j]; 
			} 
			else
			{
				int k = j / w[i];	//第i种最多放多少件
				for(int m = 0; m <= k; m++)
				{
					if(dp[i-1][j-m*w[i]]+m*v[i] > dp[i][j])
					{
						dp[i][j] = dp[i-1][j-m*w[i]]+m*v[i];
					}
				}
			}
		}
	} 
	
	cout << dp[N][W];
	
	return 0;
}

