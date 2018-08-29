#include <iostream>
using namespace std;


template <class T>
class linked_list;

template <class T>
class nodo
{
private:
	T dato;
	nodo<T> *p_next;
public:
	nodo(const T & d, nodo<T> *n=NULL);
	void print();
friend class linked_list<T>;
};

template <class T>
class linked_list
{
protected:
	nodo<T> * p_head;
	nodo<T> * p_last;
public:
	linked_list();
	void insert_front(const T & d);
	void insert_back(const T & d);
	void remove_front();
	void remove_back();
	void print();
};

template <class T>
class cola:public linked_list<T>
{
public:
	cola();
	void push_cola(const T & d);
	void pop_cola();
};

template <class T>
class pila:public linked_list<T>
{
public:
	pila();
	void push_pila(const T & d);
	void pop_pila();
};