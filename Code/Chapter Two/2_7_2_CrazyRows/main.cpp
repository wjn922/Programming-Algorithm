#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int MAXN = 1000;
int N;
int M[MAXN][MAXN];		//��ʼ����
int a[MAXN];			//a[i]��ʾ��i�������ֵ�1��λ��   0~n-1,�����̬�仯 
int res;

void solve()
{
	//��ʼ�����������ж�������1,  ��Ϊ-1
	for(int i = 0; i < N; i++)
	{
		a[i] = -1;
		for(int j = 0; j < N; j++)
		{
			if(M[i][j] == 1)
				a[i] = j;
		}
	}
	
	for(int i = 0; i < N; i ++)		//һ��һ��ȷ���任�����ĵ�i��Ϊԭʼ����ĵڼ��� 
	{
		int pos = -1;		//Ҫ�ƶ��� ��i�е���
		for(int  j = i; j< N;j++)
		{
			if(a[j] <= i)
			{ 
				pos = j;
				break;		//���������ܹ��Ƶ���i�� ���У�ѡ�������һ�� 
			} 
		} 
		
		//��ɽ���
		for(int j = pos; j > i; j--)
		{
			swap(a[j], a[j-1]);
			res++;
		} 
	}
	 
} 


int main(int argc, char** argv) {
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
			cin >> M[i][j];
	}
	
	solve();
	cout << res;
	return 0;
}
