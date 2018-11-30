#pragma once
#include "listNode.h"
using std::cout;
using std::endl;
template <typename T> class List
{
private:
	int _size; ListNodePosi(T) header; ListNodePosi(T) trailer;

public:
	List() { init(); }
	~List() { };

	//只读访问接口
	void print() const;
	T& operator[] (Rank r) const;
	ListNodePosi(T) first() const { return header->succ; }
	ListNodePosi(T) last() const { return trailer->pred; }

	//可写接口
	ListNodePosi(T) insertAsFirst( T const& e);
	ListNodePosi(T) insertAsLast(T const& e);
	ListNodePosi(T) insertA(ListNodePosi(T) p, T const& e);//e作为p后继插入
	ListNodePosi(T) insertB(ListNodePosi(T) p, T const& e);//e作为p前驱插入
protected:
	void init();
	int clear();
};

template <typename T> void List<T>::init()
{
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->pred = NULL; header->succ = trailer;
	trailer->pred = header; trailer->succ = NULL;
	_size = 0;
}

template <typename T> void List<T>::print() const
{
	cout << "size:" << _size << endl;
	cout << header->pred << endl;
}



template <typename T> T& List<T>::operator[] (Rank r) const
{
	ListNodePosi(T) p = first();
	while (0 < r--) p = p->succ;
	return p->data;
}

template<typename T>
ListNodePosi(T) List<T>::insertAsFirst(T const & e)
{
	_size++;
	return header->insertAsSucc( e );
}

template<typename T>
ListNodePosi(T) List<T>::insertAsLast(T const & e)
{
	_size++;
	return trailer->insertAsPred( e );
}

template<typename T>
ListNodePosi(T) List<T>::insertA(ListNodePosi(T) p, T const & e)
{
	_size++;
	return p->insertAsPred( e );
}

template<typename T>
ListNodePosi(T) List<T>::insertB(ListNodePosi(T) p, T const & e)
{
	_size++;
	return p->insertAsPred( e );
}



