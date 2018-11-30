#pragma once
#include <iostream>
typedef	int Rank;
#define ListNodePosi(T) ListNode<T>*

template <typename T> struct ListNode
{
	T data; ListNodePosi(T) pred; ListNodePosi(T) succ;
	ListNode() {};
	ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
		: data(e), pred(p), succ(s) {};

	ListNodePosi(T) insertAsPred(T const& e);
	ListNodePosi(T) insertAsSucc(T const& e);
};

template <typename T> ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e)
{
	ListNodePosi(T) x = new ListNode(e, this, succ);
	succ->pred = x;
	succ = x;
	return x;
}
