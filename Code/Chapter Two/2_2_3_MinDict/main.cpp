//贪心，每次取字符串S开头和末尾中较小的放到T的末尾
//若S开头和末尾字符相同，则需要继续比较，因此采用字符串翻转S'，比较S和S' 
//若S小，就从S开头取一个，若S'小，从S末尾取一个，若相同都可以 
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
		//将左起字符串和右起字符串比较
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
