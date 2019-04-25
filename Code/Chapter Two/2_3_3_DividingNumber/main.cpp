#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 10000;
int n, m, M;
int dp[MAXN][MAXN];  //dp[i][j] 为数j的i份划分 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cin >> n >> m >> M;
	
	dp[0][0] = 1;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			if(j-i>=0)
				dp[i][j] = dp[i-1][j] + dp[i][j-i];
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	
	cout << dp[m][n]; 
	return 0;
}
