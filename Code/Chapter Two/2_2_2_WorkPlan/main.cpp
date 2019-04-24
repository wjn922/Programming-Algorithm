//贪心，选择结束时间最早的工作
#include<iostream>
#include <cmath>
#include <map>
//#include <pair> 
#include <algorithm>
using namespace std;

const int MAXN = 100000;
int n, S[MAXN], T[MAXN];
int vis[MAXN] = {0};	
pair<int, int> Work[MAXN];	//记录每个工作的起始和结束时间, first为T， second为S 

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
	
	//t是所选工作的结束时间
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
