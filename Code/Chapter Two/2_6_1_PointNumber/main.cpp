#include <iostream>
#include <cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int x1, y1, x2, y2;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	
	int a = abs(x1-x2);
	int b = abs(y1-y2);
	
	if(a==0 && b==0)
	{
		cout << "0";
		return 0;
	}
	
	if(a<b)
		swap(a,b);
		
	while(a%b!=0)
	{
		int c = a%b;
		a = b;
		b = c;
	}
	//最大公约数为b 
	cout << b-1;
	return 0;
}
