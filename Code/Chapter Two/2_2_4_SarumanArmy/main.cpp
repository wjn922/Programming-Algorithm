//̰�ģ��ȴӵ�һ���㿼�ǣ���һ����ǵ�����R�ĵط��ǵ�һ���� 
#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 100000;
int N, R;
int X[MAXN];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cin >> N >> R;
	for(int i = 0; i < N; i++)
		cin >> X[i];
		
	int ans = 1;
	int loc = X[0] + R - 1;
	for(int i = 1; i < N; i++)
	{
		if(abs(loc-X[i]) >= R)
		{
			loc = X[i] + R - 1;
			ans++;
		}
	}
	
	cout << ans;
	return 0;
}
