#include "Stack.h"

using std::cout;
using std::endl;

void convert(_int64, int);//10进制转任意进制
int main()
{
	//Stack<int> Stack1;
	//cout << Stack1.top() << endl;

	convert(9, 2);
	system(" pause ");
	return 0;
}

void convert( _int64 n, int base)//十进制数n转任意base进制
{
	Stack<char> S;
	int i = 0;
	char j;
	static char digit[]
		= { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	while ( n > 0 )
	{
		S.push(digit[n % base]);
		n = n / base;
		i++;
	}
	while (i > 0)
	{
		if ( i == 1 )
		{
			cout << S.pop() << endl; 
		}
		else
		{
			cout << S.pop();
		}
		i--;
	}
}