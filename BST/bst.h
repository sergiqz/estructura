#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template <class K, class D>
class bst;

template <class K, class D>
class node
{
private:
	K key;
	D data;
	node<K,D> *p_child[2];
public:
	node(const K & k, const D & d);
	virtual ~node(){};
	friend class bst<K,D>;
};

template <class K, class D>
class bst
{
private:
	node<K,D> *p_root;
public:
	bst():p_root(NULL){};
	virtual ~bst(){};
	bool find(const K & key, D & data);
	bool insert(const K & key, const D & data);
	void print();
	void print(node<K,D> *n);
	void remove(const K & key);
	void remove(node<K,D>** n,const K & key);
	bool remove_v2(K key);

private:
	bool find(const K & key, node<K,D> **& n);
};

#include "bst.inl"
#endif