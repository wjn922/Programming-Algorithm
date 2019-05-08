#include <iostream>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
//扩展辗转相除法

//返回值是gcd(a,b) 即a,b的最大公约数 
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
		x = y;   			//商 
		y = t - (a/b)*y;	//余数 
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
