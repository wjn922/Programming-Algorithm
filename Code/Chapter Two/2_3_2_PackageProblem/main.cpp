#include <iostream>
#include <cmath>
#include <algorithm> 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�Ա�����������Ż���ֻ��һά���鼴�ɽ��01��������ȫ�������� 

const int MAXN = 10000;
int N, W;
int w[MAXN+1], v[MAXN+1];
int dp1[MAXN+1];  	//01�������� 
int dp2[MAXN+1];	//��ȫ�������� 

int main(int argc, char** argv) {
	cin >> N >> W;
	for(int i = 1; i <= N; i++)
		cin >> w[i];
	for(int i = 1; i <= N; i++)
		cin >> v[i];
	
	
	
	//01���� 
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
	
	//��ȫ���� 
	for(int i = 1; i <= N; i++ )
	{
		for(int j = 1; j <= W; j++) 	//���01���������Ż����룬ֻ�ǻ��˱����������
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
