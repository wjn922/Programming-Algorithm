//̰���㷨�����������Ӳ�� 
#include <iostream>
#include <cmath>
using namespace std;

const int V[6] = {1, 5, 10, 50, 100, 500};
int C[6];		//ÿ��Ӳ�ҵ�����
int A;		//������ֵ 
int ans = 0;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	for(int i = 0; i < 6; i++)
		cin >> C[i];
	cin >> A;
	
	for(int i = 5; i >=0; i--)
	{
		int t = min(A/V[i], C[i]);	//ʹ�õ�i��Ӳ�ҵ�����
		A -= t * V[i];
		ans++;
	}
	
	cout << ans;
	return 0;
}
