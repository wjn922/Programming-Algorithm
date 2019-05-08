#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//°£¼°É¸·¨ 
const int MAXN = 100000;
int n;
int vis[MAXN] = {0};
int count = 0;

int main(int argc, char** argv) {
	cin >> n;
	for(int i = 2; i <= n; i++)
	{
		if(vis[i])	continue;
		else
		{
			count++;
			int k = n / i;
			for(int j = 1; j <=k; j++)
			{
				vis[i*j] = 1;
			}
		}
	}
	
	cout << count;
	return 0;
}
