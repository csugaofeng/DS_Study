#include <iostream>
#include <algorithm>
using std::cout;
using std::max;
using std::endl;
#include "BinTree.h"

int main()
{
	BinTree<int> a;
	a.insertAsRoot(1);
	BinNodePosi(int) root = a.root();
	cout << root->height << endl;
	BinNodePosi(int) node1 = a.insertAsLC(root, 2);
	BinNodePosi(int) node2 = a.insertAsRC(root, 3);
	BinNodePosi(int) node11 = a.insertAsLC(node1, 4);
	BinNodePosi(int) node12 = a.insertAsRC(node1, 5);
	BinNodePosi(int) node21 = a.insertAsLC(node1, 6);
	BinNodePosi(int) node22 = a.insertAsRC(node1, 7);
	BinNodePosi(int) node12_ = a.insertAsRC(node1, 8);
	int k = a.size();
	cout << root->lc->rc->data<<","<<k<<endl;

	system(" pause ");
	return 0;
}