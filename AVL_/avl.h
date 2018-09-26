#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

template <class K, class D>
class avl;

template <class K, class D>
class node
{
private:
	K key;
	D data;
	int BalanceFactor;
	node<K,D> *p_child[2];
public:
	node(const K & k, const D & d);
	virtual ~node(){};
	friend class avl<K,D>;
};

template <class K, class D>
class avl
{
private:
	node<K,D> *p_root;
	ofstream os;
public:
	avl():p_root(NULL), os("grap.dot"){};
	bool find(node<K,D> **& n, const K & key);
	bool find(const K & key, D & data);
	void insert(const K & key,const D & data);
	bool insert(node<K,D> **n,const K & key,const D & data);
	bool checkNbalalnce(node<K,D> **n);
	bool turnSide(node<K,D> **n, bool side);
	int getSize();
	int getSize(node<K,D> *n);
	bool remove(node<K,D> **n);
	bool remove(const K & key);
	bool remove(node<K,D> **n, const K & key);
	node<K,D>* getParent(const K & key);
	void print(node<K,D> *n);
	void print(int num);
	virtual ~avl(){};

private:
	
};

#include "avl.inl"
#endif