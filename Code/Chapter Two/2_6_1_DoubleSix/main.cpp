#include <iostream>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
//��չշת�����

//����ֵ��gcd(a,b) ��a,b�����Լ�� 
int extendgcd(int a, int b, int &x, int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	else
	{
		int r = extendgcd(b, a%b, x, y);
		int t = x;
		x = y;   			//�� 
		y = t - (a/b)*y;	//���� 
		return r;
	}
}
int main(int argc, char** argv) {
	int a, b, x, y;
	cin >> a >> b;
	
	if(extendgcd(a,b,x,y) != 1)
		cout << "0";
	else
		cout << abs(x) + abs(y);
	
	return 0;
}
