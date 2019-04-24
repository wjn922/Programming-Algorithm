//贪心算法，先用面额大的硬币 
#include <iostream>
#include <cmath>
using namespace std;

const int V[6] = {1, 5, 10, 50, 100, 500};
int C[6];		//每种硬币的数量
int A;		//最终面值 
int ans = 0;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	for(int i = 0; i < 6; i++)
		cin >> C[i];
	cin >> A;
	
	for(int i = 5; i >=0; i--)
	{
		int t = min(A/V[i], C[i]);	//使用第i种硬币的数量
		A -= t * V[i];
		ans++;
	}
	
	cout << ans;
	return 0;
}
