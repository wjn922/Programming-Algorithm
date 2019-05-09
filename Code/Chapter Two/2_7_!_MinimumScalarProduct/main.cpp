#include <iostream>
#include <algorithm> 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//贪心，一个向量正序，一个向量逆序，相乘即可 

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
		
	sort(v1, v1+n);        //从小到大 
	sort(v2, v2+n, cmp);   //从大到小 
	int ans = 0;	
	for(int i = 0; i < n; i++)
	{
		ans += v1[i] * v2[i];
	}
	

	cout << ans << endl;
	return 0;
}
