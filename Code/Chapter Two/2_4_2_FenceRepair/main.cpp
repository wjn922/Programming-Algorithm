#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <functional>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
���öѣ���Чʵ��,ÿ��ȡ����̵������ 
����N��logN�Ĳ���   O��NlogN�� 
*/
int N;
int L[10000];
priority_queue <int, vector<int>, greater<int> > Wood; //��С��
int ans = 0;

int main(int argc, char** argv) {
	cin >> N;
	for(int i = 0; i < N ;i++)
		cin >> L[i];
	for(int i = 0; i < N; i++)
		Wood.push(L[i]);
		
	
	while(Wood.size() > 1)
	{
		int l1, l2;
		l1 = Wood.top();
		Wood.pop();
		l2 = Wood.top();
		Wood.pop();
		
		int t = l1 + l2;
		ans += t;
		
		Wood.push(t);
	}	
	
	cout << ans;
	return 0;
}
