//̰�ģ�ÿ��ȡ�ַ���S��ͷ��ĩβ�н�С�ķŵ�T��ĩβ
//��S��ͷ��ĩβ�ַ���ͬ������Ҫ�����Ƚϣ���˲����ַ�����תS'���Ƚ�S��S' 
//��SС���ʹ�S��ͷȡһ������S'С����Sĩβȡһ��������ͬ������ 
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std; 

const int MAXN = 100000;
int N;
string S;
string T = "";
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cin >> N;
	cin >> S;
	
	int a = 0, b = N-1;
	string temp;
	while(a <= b)
	{
		bool left = false;
		//�������ַ����������ַ����Ƚ�
		for(int i = 0; a+i<=b; i++)
		{
			if(S[a+i] < S[b-i])
			{
				left = true;
				break;
			}
			else if(S[a+i] > S[b-i])
			{
				left = false;
				break;
			}
		} 
		
		if(left)
		{
			temp = S[a];
			T.append(temp);
			a++;
		}
		else
		{
			temp = S[b];
			T.append(temp);
			b--;
		}
	}
	
	cout << T;
	return 0;
}
