#include "Stack.h"

using std::cout;
using std::endl;
int main()
{
	Stack<int> Stack1;
	Stack1.push(1);
	Stack1.push(2);
	Stack1.push(3);
	Stack1.push(4);

	cout << Stack1.top() << endl;
	system(" pause ");
	return 0;
}
