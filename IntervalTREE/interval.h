#ifndef INTERVAL_H
#define INTERVAL_H

#include <iostream>
#include <fstream>
#include <stdlib.h> 
using namespace std;

class intervalTree;

class node
{
private:
	int low;
	int high;
	int max;
	int BalanceFactor;
	node *p_child[2];
public:
	node(const int & l, const int & h);
	friend class intervalTree;
};

class intervalTree
{
private:
	node *root;
public:
	intervalTree();
	bool insert(node **n,const int & l,const int & h);
	void insert(const int & l, const int & h);
	bool find(node **& n, const int & l);
	bool find(const int & l, const int & h);
	bool checkNbalalnce(node **n);
	bool turnSide(node **n, bool side);
	int getSize();
	int getSize(node *n);
	bool dooverlap(node *i1, const int & l, const int & h);
	node * overlapSearch(node ** n, const int & l, const int & h);
	void overlapSearch(const int & l, const int & h);
	void print();
	void print(node *n, ofstream & os);
};

#include "interval.inl"
#endif