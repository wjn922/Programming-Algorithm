#include <iostream>
#include <algorithm> 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//̰�ģ�һ����������һ������������˼��� 

const int MAXN = 10000;
int n;
int v1[MAXN];
int v2[MAXN];

bool cmp(int a, int b)
{
	return a>b;
}
int main(int argc, char** argv) {
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> v1[i];
	for(int i = 0; i < n; i++)
		cin >> v2[i];
		
	sort(v1, v1+n);        //��С���� 
	sort(v2, v2+n, cmp);   //�Ӵ�С 
	int ans = 0;	
	for(int i = 0; i < n; i++)
	{
		ans += v1[i] * v2[i];
	}
	

	cout << ans << endl;
	return 0;
}
