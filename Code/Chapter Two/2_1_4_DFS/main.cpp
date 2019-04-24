#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAXN 10000
int A[MAXN];
int n, k;

bool dfs(int num, int currentSum)
{
	if(num == n)
	{
		return currentSum==k;
	}
	
	//������A[i] 
	if(dfs(num+1, currentSum))	
		return true;
	//����A[i]	
	if(dfs(num+1, currentSum+A[num])) 
		return true;
		
	return false;
}
int main(int argc, char** argv) {
	cin >> n >> k;		//�ܹ�n�������Ӻ�Ϊk 
	for (int i = 0; i < n; i++)
		cin >> A[i];
		
	if(dfs(0,0))	
		cout << "Yes" << endl;
	else 
		cout << "No" << endl; 
	return 0;
}
