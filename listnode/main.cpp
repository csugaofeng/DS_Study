#include "listNode.h"
using std::cout;
using std::endl;
int main()
{
	ListNodePosi(int) header = new ListNode<int>;
	ListNodePosi(int) trailer = new ListNode<int>;
	ListNodePosi(int) Node1;
	header->pred = NULL; header->succ = trailer;
	trailer->pred = header; trailer->succ = NULL;
	int e = 5;
	Node1 = header->insertAsSucc(e);
	
	
	cout << Node1->data<< endl;

	system("pause");
	return 0;
}