//DP
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int MAXN = 10000;
int N, W;
int w[MAXN+1], v[MAXN+1];
int dp[MAXN+1][MAXN+1];

int main(int argc, char** argv) {
	cin >> N >> W;
	for(int i = 1; i <= N; i++)
		cin >> w[i];
	for(int i = 1; i <= N; i++)
		cin >> v[i];
	
	if(w[1] < W)
	{
		for(int j = w[1]; j <= W; j++)
			dp[1][j] = v[1];
	}
	
	//dp
	//第x件放与不放，选其中总价值大的
	for(int i = 2; i <= N; i++)
	{
		for(int j = 1; j <= W; j++)
		{
			if(j>w[i])
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
			else
				dp[i][j] = dp[i-1][j];
		}
	} 
	
	cout << dp[N][W];
	
	return 0;
}
