#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int MAXN = 1000;
int N;
int M[MAXN][MAXN];		//初始矩阵
int a[MAXN];			//a[i]表示第i行最后出现的1的位置   0~n-1,随程序动态变化 
int res;

void solve()
{
	//初始化，置所有行都不存在1,  即为-1
	for(int i = 0; i < N; i++)
	{
		a[i] = -1;
		for(int j = 0; j < N; j++)
		{
			if(M[i][j] == 1)
				a[i] = j;
		}
	}
	
	for(int i = 0; i < N; i ++)		//一行一行确定变换后矩阵的第i行为原始矩阵的第几行 
	{
		int pos = -1;		//要移动到 第i行的行
		for(int  j = i; j< N;j++)
		{
			if(a[j] <= i)
			{ 
				pos = j;
				break;		//对于所有能够移到第i行 的行，选择最近的一个 
			} 
		} 
		
		//完成交换
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
