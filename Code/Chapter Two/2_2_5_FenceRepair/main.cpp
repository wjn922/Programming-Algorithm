//��С�İ�Ӧ�����������ӽڵ�֮һ
//̰�ģ��ӵ����� 
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
int N, L[MAXN];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cin >> N;
	for(int i = 0; i < N; i ++)
		cin >> L[i];
		
	int ans = 0;
	//���㵽ֻʣһ��� 
	while(N > 1) 
	{
		int minindex1 = 0, minindex2 = 1;
		//����̵������
		if(L[minindex1] > L[minindex2]) 
			swap(minindex1, minindex2);
			
		for(int i = 2; i < N; i++)
		{
			if(L[i] < L[minindex1])
			{
				minindex1 = i;
				minindex2 = minindex1;
			}
			else if(L[i] < L[minindex2])
			{
				minindex2 = i;
			}
		}
		
		//��������ƴ��
		int t = L[minindex1] + L[minindex2];
		ans += t;
		
		if(minindex1 == N-1) 
			swap(minindex1, minindex2);
		L[minindex1] = t;
		L[minindex2] = L[N-1];
		
		N--;
	} 
	
	cout << ans;
	return 0;
}
