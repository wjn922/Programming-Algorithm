#include <iostream>
#include <cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int MAXN = 10000;
int N;
int a[MAXN];
int dp[MAXN];	//dp[i]Ϊ��a[i]��β�����е�������г��� 
int ans = 0;	//��������������� 


int main(int argc, char** argv) {
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> a[i]; 
	}
	
	//dp
	for(int i = 0; i < N; i++) 
	{
		dp[i] = 1;
		for(int j = 0; j < i; j++)
		{
			if(a[j] < a[i])
			{
				dp[i] = max(dp[i], dp[j]+1);
			}
		} 
		ans = max(ans, dp[i]);
	}
	
	cout << ans;
	return 0;
}
