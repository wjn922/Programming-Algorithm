#include <iostream>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
1. 认为在经过加油站i时就获得了之后任何时候加Bi油的权利，加到优先队列里 
2. 为了使加油数尽可能少，当油耗尽时选择优先队列里的 最大加油量
3. 当燃料为0而优先队列为空时，不能到达
*/
 
const int MAXN = 100000;
int N, L, P;
queue <int> A, B;	//距离起点距离，最多加油量 
priority_queue <int> gas;
int count = 0;
int flag = 1;	//是否完成

int main(int argc, char** argv) {
	
	cin >> N >> L >> P;
	for(int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		A.push(temp);
	}
	for(int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		B.push(temp);
	}
	
	//一开始就加满油	
	if(P >= L)	
	{
		cout << "0";
		return 0;
	}
		
	
	
	//需要 途中加油 		
	for(int i = 0; i <= L; i++)	//从起点到终点
	{
		//cout << i << endl;
		//cout << P << endl;
		if (P < 0)		//没有燃料，退出行程 
		{
			flag = 0;
			break;	
		}
		else
		{
			if(i == A.front())	//到达一个加油站 
			{
				A.pop();
				gas.push(B.front());
				B.pop(); 
			}
			
			
			if(i == L)	//到达终点 
				break; 
			if(P == 0 && !gas.empty())	//需要加油 
			{
				P += gas.top();
				gas.pop();
				count++;
			}
			
			
			P--;
			 
		} 
	}
	 
	
	
	//输出
	if(flag)
		cout << count;
	else
		cout << "-1"; 
	
	return 0;
}
