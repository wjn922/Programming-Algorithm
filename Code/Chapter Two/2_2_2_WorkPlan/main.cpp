//̰�ģ�ѡ�����ʱ������Ĺ���
#include<iostream>
#include <cmath>
#include <map>
//#include <pair> 
#include <algorithm>
using namespace std;

const int MAXN = 100000;
int n, S[MAXN], T[MAXN];
int vis[MAXN] = {0};	
pair<int, int> Work[MAXN];	//��¼ÿ����������ʼ�ͽ���ʱ��, firstΪT�� secondΪS 

int ans = 0;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> S[i];
	for(int i = 0; i < n; i++)
		cin >> T[i];
	
	for(int i = 0; i<n ;i++)
	{
		Work[i].first = T[i];
		Work[i].second = S[i];
	}
	
	sort(Work, Work+n);
	
	//t����ѡ�����Ľ���ʱ��
	int t = 0;
	for(int i = 0; i < n; i++)
	{
		if(Work[i].second > t)
		{
			t = Work[i].first;
			ans++;
		}
	} 
	
	cout << ans;
	return 0;
} 
