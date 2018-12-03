typedef int Rank;
#define DEFAULT_CAPACITY 3

#include "fib.h"
#include <iostream>
#include <time.h>
using std::cout;
using std::endl;
using std::swap;
template <typename T> class Vector
{
protected:
	Rank _size;//数组规模
	int _capacity;//数组容量
	T* _elem;//数据区域
	void copyFrom(T const* A, Rank lo, Rank hi);//赋值数组区间A[lo,hi]
	void expand();//空间不足时扩容
	void expand(Rank lo, Rank hi);
	void shrink();//装填因子过小时压缩向量所占空间
public:
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)
	{
		_elem = new T[_capacity = c];
		for (_size = 0; _size < s; _size++)
		{
			_elem[_size] = v;
		}
	}
	Vector(T const* A, Rank lo, Rank hi)
	{
		copyFrom(A, lo, hi);
	}

	~Vector() { delete[] _elem; }
	//只读接口
	Rank size() const
	{
		return _size;
	}
	Rank find(T const& e) const 
	{ 
		return find(e, 0, _size); 
	}
	Rank find(T const& e, Rank lo, Rank hi) const;
	void showall() const;
	//可写接口
	T& operator[] (Rank r) const;
	Vector<T>& operator= (Vector<T> const&);
	Rank insert(Rank r, T const& e);
	Rank insert(T const& e)
	{
		return insert(_size, e);
	}
	Rank insert(Rank r, T const* e, Rank lo, Rank hi);
	T remove(Rank r);
	Rank remove(Rank lo, Rank hi);
	void unsort(Rank lo, Rank hi);
	void bubbleSort(Rank lo, Rank hi);//冒泡排序
	bool bubble(Rank lo, Rank hi);//一趟扫描交换
	void merge(Rank lo, Rank mi, Rank hi);
	void mergeSort(Rank lo, Rank hi);

	int uniquify();
};


template <typename T> void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi)
{
	_elem = new T[_capacity = 2 * (hi - lo)];
	_size = 0;
	while (lo < hi)
	{
		_elem[_size] = A[lo];
		lo++;
		_size++;
	}
}

template <typename T> T& Vector<T>::operator[] (Rank r) const
{
	return _elem[r];
}

template <typename T> void Vector<T>::showall() const
{
	int i = 0;
	cout << "The element are {";
	for (i; i < _size; i++)
		if (i != _size - 1)
			cout << _elem[i] << ",";
		else
			cout << _elem[i];
	cout << "}" << endl;
	cout << "The size is " << _size << endl;
	cout << "The capacity is " << _capacity << endl;
}

template <typename T> Vector<T>& Vector<T>::operator= (Vector<T> const& V)
{
	if (_elem)
		delete[] _elem;
	copyFrom(V._elem, 0, V._size);
	return *this;
}

template <typename T> void Vector<T>::expand()
{
	if (_size < _capacity)
		return;
	if (_capacity < DEFAULT_CAPACITY)
		_capacity = DEFAULT_CAPACITY;
	T* oldElem = _elem;
	_elem = new T[_capacity <<= 1];
	for (int i = 0; i < _size; i++)
	{
		_elem[i] = oldElem[i];
	}
	delete[] oldElem;
}

template <typename T> void Vector<T>::expand(Rank lo, Rank hi)
{
	int num = hi - lo;
	if (_capacity < DEFAULT_CAPACITY)
		_capacity = DEFAULT_CAPACITY;
	while ((_capacity - _size) < num)
	{
		T* oldElem = _elem;
		_elem = new T[_capacity <<= 1];
		for (int i = 0; i < _size; i++)
		{
			_elem[i] = oldElem[i];
		}
		delete[] oldElem;
	}
}

template <typename T> void Vector<T>::shrink()
{
	if (_capacity < DEFAULT_CAPACITY << 1)
		return;
	if (_size << 2 > _capacity)
		return;
	T* oldElem = _elem;
	_elem = new T[_capacity >>= 1];
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];
	delete[] oldElem;
}

template <typename T> Rank Vector<T>::insert(Rank r, T const& e)
{
	expand();
	for (int i = _size; i > r; i--)
		_elem[i] = _elem[i - 1];
	_elem[r] = e;
	_size++;
	return r;
}

template <typename T> Rank Vector<T>::insert(Rank r, T const* e, Rank lo, Rank hi)
{
	int num = hi - lo;
	expand(lo, hi);
	for (int i = (_size + num - 1); i > (r + num - 1); i--)
		_elem[i] = _elem[i - num];
	for (int i = r; i < (r + num); i++)
	{
		_elem[i] = e[lo];
		lo++;
	}
	_size = _size + num;
	return r;
}

template<typename T>
T Vector<T>::remove(Rank r)
{
	T e = _elem[r];
	remove(r, r + 1);
	return e;
}

template <typename T> Rank Vector<T>::remove(Rank lo, Rank hi)
{
	if (lo == hi)
		return 0;
	while (hi < _size)
	{
		//_elem[lo] = _elem[hi];
		//lo++;
		//hi++;
		_elem[lo++] = _elem[hi++];
	}
	_size = lo;
	shrink();
	return hi - lo;
}

template <typename T> void Vector<T>::unsort(Rank lo, Rank hi)
{
	srand((unsigned)time(NULL));
	T* V = _elem + lo;
	for (Rank i = hi - lo; i > 0; i--)
		swap(V[i - 1], V[rand() % i]);
}

template <typename T> int Vector<T>::uniquify()
{
	Rank i = 0, j = 0;
	while (++j < _size)
	{
		if (_elem[i] != _elem[j])
			_elem[++i] = _elem[j];
	}
	_size = ++i;
	shrink();
	return j - i;

}

template <typename T> static Rank binSearch(T* A, T const& e, Rank lo, Rank hi)//A必须是有序的
{
	while (1 < hi - lo)
	{
		Rank mi = (lo + hi) >> 1;
		(e < A[mi]) ? hi = mi : lo = mi;
	}
	return (e == A[lo]) ? lo : -1;
}

template <typename T> static Rank fibSearch(T* A, T const& e, Rank lo, Rank hi)
{
	Fib fib(hi - lo);
	while (lo < hi)
	{
		while (hi - lo < fib.get())
			fib.prev();
		Rank mi = lo + fib.get() - 1;
		if (e < A[mi]) hi = mi;
		else if (A[mi] < e) lo = mi + 1;
		else return mi;
	}
}

template <typename T> Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const
{
	while ((lo < hi--) && (e != _elem[hi]));
	return hi;
}

template <typename T> void Vector<T>::bubbleSort(Rank lo, Rank hi)
{
	while (!bubble(lo, hi--));
}

template <typename T> bool Vector<T>::bubble(Rank lo, Rank hi)
{
	bool sorted = true;
	while ( ++lo < hi )
	{
		if (_elem[lo - 1] > _elem[lo])
		{
			sorted = false;
			swap(_elem[lo - 1], _elem[lo]);
		}
	}
	return sorted;
}

template <typename T> void Vector<T>::mergeSort(Rank lo, Rank hi)
{
	if (hi - lo < 2)
		return;
	int mi = (hi - lo) / 2;
	mergeSort(lo, mi); mergeSort(mi, hi);
	merge(lo, mi, hi);
}

template <typename T> void Vector<T>::merge(Rank lo, Rank mi, Rank hi)
{
	T* A = _elem + lo;
	int lb = mi - lo;
	T* B = new T[lb];
	for (Rank i = 0; i < lb; B[i] = A[i++]);
	int lc = hi - mi;
	T* C = _elem + mi;
	for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);)
	{
		if ((j < lb) && (!(k < lc) || (B[j] <= C[k])))
			A[i++] = B[j++];
		if ((k < lc) && (!(j < lb) || (C[k] < B[j])))
			A[i++] = C[k++];
	}
	delete[] B;
}