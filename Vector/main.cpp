#include "Vector.h"
#include "fib.h"
#include <iostream>

typedef int Rank;

int main()
{
	using std::cout;
	using std::endl;
	int A[5] = { 1,2,3,4,5 };
	int B[16] = { 8,8,8,8 };
	int num1,num2;
	Vector<int> st(A, 0, 5);
	st.unsort(0, 5);
	st.showall();
	st.bubbleSort(0, 3);
	st.showall();
	//cout << num << endl;

	system("pause");
	return 0;
}