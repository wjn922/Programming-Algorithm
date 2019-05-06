#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int MAXN = 10000;
int d[MAXN][MAXN];
int V;

void floyd()
{
	for(int k = 0; k < V; k ++)
	{
		for(int i = 0; i < V;i ++)
		{
			for(iint j = 0; j < V; j ++)
				d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
		}
	}
}
int main(int argc, char** argv) {
	return 0;
}
