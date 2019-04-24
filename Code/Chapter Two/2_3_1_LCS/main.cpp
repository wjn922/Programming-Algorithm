#include <iostream>
#include <cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int MAXN = 10000;
int N, M;
string s1, s2;
int dp[MAXN][MAXN] = {0};

int main(int argc, char** argv) {
	cin >> s1 >> s2;
	N = s1.size();
	M = s2.size();
	
	//第一列
	int index1 = MAXN;
	for(int i = 0; i < N; i++)
	{
		if(s1[i] == s2[0])
			index1 = i;
	} 
	if(index1 < N)
	{
		for(int i = index1; i < N; i++)
			dp[i][0] = 1;
	}
	
	//第一行 
	int index2 = MAXN;
	for(int j = 0; j < M; j++)
	{
		if(s2[j] == s1[0])
			index2 = j;
	} 
	if(index2 < M)
	{
		for(int j = index2; j < M; j++)
			dp[0][j] = 1;
	}
	
	//dp
	for(int i = 1; i < N; i++)
	{
		for(int j = 1; j < M; j++)
		{
			if(s1[i] == s2[j])
			{
				int temp = max(dp[i-1][j], dp[i][j-1]);
				dp[i][j] = max(temp, dp[i-1][j-1]+1);
			}
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	cout << dp[N-1][M-1];
	return 0;
}
