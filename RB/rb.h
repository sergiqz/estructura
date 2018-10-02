#ifndef RB_H
#define RB_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stack>

using namespace std;

enum color_t: bool {BLACK = 0, RED = 1};

template<class K, class D>
class rb;

template<class K, class D>
class node
{
private:
	K key;
	D data;
	color_t color;
	node<K,D> *parent;
	node<K,D> *p_child[2];
public:
	node();
	~node(){};
	node(const K & k, const D & d);
	friend class rb<K,D>;
};

template<class K, class D>
class rb
{
private:
	node<K,D> *p_root;
public:
	rb();
	~rb(){};
};

#include "rb.inl"
#endif