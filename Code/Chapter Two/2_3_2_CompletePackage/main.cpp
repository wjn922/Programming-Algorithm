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
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j <= W; j++)
		{
			if(j>=w[i])
				dp[i+1][j] = max(dp[i][j], dp[i+1][j-w[i]]+v[i]);
			else
				dp[i+1][j] = dp[i][j];
		}
	} 
	
	cout << dp[N][W];
	
	return 0;
}

