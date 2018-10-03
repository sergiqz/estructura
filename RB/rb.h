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
	node(const K & k, const D & d);
	~node(){};
	friend class rb<K,D>;
};

template<class K, class D>
class rb
{
private:
	node<K,D> *p_root;
public:
	rb();
	void insert(const K & key,const D & data);
	void fixInsertRBTree(node<K,D> *&ptr);
	void rotacionizq(node<K,D>*& ptr);
    void rotacionder(node<K,D>*& ptr);
	bool turnSide(node<K,D> **n, bool side);
	color_t getColor(node<K,D> *&n);
    void setColor(node<K,D> *&n, color_t color);
    void printARBOL(ofstream & es,node<K,D> *n);
    void printARBOL(int num);
    void printCOLOR(ofstream & es,node<K,D> *n);
	~rb(){};
};

#include "rb.inl"
#endif