#include <iostream>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
1. ��Ϊ�ھ�������վiʱ�ͻ����֮���κ�ʱ���Bi�͵�Ȩ�����ӵ����ȶ����� 
2. Ϊ��ʹ�������������٣����ͺľ�ʱѡ�����ȶ������ ��������
3. ��ȼ��Ϊ0�����ȶ���Ϊ��ʱ�����ܵ���
*/
 
const int MAXN = 100000;
int N, L, P;
queue <int> A, B;	//���������룬�������� 
priority_queue <int> gas;
int count = 0;
int flag = 1;	//�Ƿ����

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
	
	//һ��ʼ�ͼ�����	
	if(P >= L)	
	{
		cout << "0";
		return 0;
	}
		
	
	
	//��Ҫ ;�м��� 		
	for(int i = 0; i <= L; i++)	//����㵽�յ�
	{
		//cout << i << endl;
		//cout << P << endl;
		if (P < 0)		//û��ȼ�ϣ��˳��г� 
		{
			flag = 0;
			break;	
		}
		else
		{
			if(i == A.front())	//����һ������վ 
			{
				A.pop();
				gas.push(B.front());
				B.pop(); 
			}
			
			
			if(i == L)	//�����յ� 
				break; 
			if(P == 0 && !gas.empty())	//��Ҫ���� 
			{
				P += gas.top();
				gas.pop();
				count++;
			}
			
			
			P--;
			 
		} 
	}
	 
	
	
	//���
	if(flag)
		cout << count;
	else
		cout << "-1"; 
	
	return 0;
}
