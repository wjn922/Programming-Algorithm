#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int MAXN = 10000;
int n, m, M;
int a[MAXN];
int dp[MAXN+1][MAXN+1]; //dp[i][j]��ǰi����Ʒ ȡ��j�� 

int main(int argc, char** argv) {
	cin >> n >> m >> M;
	for(int i = 1; i<=n; i++)
		cin >> a[i];
		
	//��һ�� ��һ����Ʒ����ȡ������ֻ��һ��
	for(int i = 0; i <=n; i++)
		dp[i][0] = 1;
	
	
	//dp
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(j-1-a[i] >= 0)
			{
				dp[i][j] = (dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1-a[i]] + M) % M;
			}
			else
				dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % M;
		}
	} 
	
	cout << dp[n][m];
	return 0;
}
