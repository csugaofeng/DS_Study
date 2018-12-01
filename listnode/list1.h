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
	~List();

	//ֻ�����ʽӿ�
	void print() const;
	T& operator[] (Rank r) const;
	ListNodePosi(T) first() const { return header->succ; }
	ListNodePosi(T) last() const { return trailer->pred; }

	//��д�ӿ�
	ListNodePosi(T) insertAsFirst( T const& e);
	ListNodePosi(T) insertAsLast(T const& e);
	ListNodePosi(T) insertA(ListNodePosi(T) p, T const& e);//e��Ϊp��̲���
	ListNodePosi(T) insertB(ListNodePosi(T) p, T const& e);//e��Ϊpǰ������
	T remove(ListNodePosi(T) p);//ɾ���ڵ�p������p��ֵ
protected:
	void init();
	int clear();//����б�
};

template <typename T> void List<T>::init()
{
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->pred = NULL; header->succ = trailer;
	trailer->pred = header; trailer->succ = NULL;
	_size = 0;
}

template<typename T>
int List<T>::clear()//����б�
{
	int oldsize = _size;
	while (0 < _size) remove(header->succ);//����ɾ���׽ڵ�
	return oldsize;
}

template<typename T>
List<T>::~List()
{
	clear();
	delete header;
	delete trailer;
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

template<typename T>
T List<T>::remove(ListNodePosi(T) p)
{
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p; _size--;
	return e;
}



