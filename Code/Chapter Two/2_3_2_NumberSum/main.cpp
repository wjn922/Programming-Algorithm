#include <iostream>
using namespace std;

const int MAXN = 10000;
int n;
int a[MAXN], m[MAXN];
int K;
int dp[MAXN][MAXN];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// dp[i][j]为用前i种数加和得到j时第i种数最多能剩余多少个
//（不能加和得到i的情况下为-1）

int main(int argc, char** argv) {
	cin >> n >> K;
	for(int i = 1 ; i <= n; i++)
		cin >> a[i];
	for(int i = 1 ; i <= n; i++)
		cin >> m[i];
		
	
	//第一行 
	for(int j = 1; j <= K; j++)
	{
		if(a[1] < K)
		{
			int maxk = K / a[1];
			if(j%a[1]==0)
			{
				if(j/a[1] <= maxk && j/a[1] <= m[1])
				 	dp[1][j] = m[1] - j/a[1];
				else
					dp[1][j] = -1;
			}
			else
				dp[1][j] = -1;
		}
		else
			dp[1][j] = -1;
	} 
	
	//dp 
	for(int i = 2;i <= n; i++)
	{
		for(int j = 1; j <= K; j++)
		{
			if(dp[i-1][j] >= 0)
				dp[i][j] = m[i];
			else if(j < a[i] && dp[i-1][j-a[i]]<=0)
				dp[i][j] = -1;
			else
				dp[i][j] = dp[i][j-a[i]]-1;
		}
	}
	
	if(dp[n][K] >= 0)	
		cout << "yes";
	else
		cout << "no";	
	return 0;
}
