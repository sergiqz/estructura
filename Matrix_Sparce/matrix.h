#ifndef MATRIX_H
#define MATRIX_H

#include <cstdio>
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>
#include <stddef.h>
using namespace std;

template <class T>
class m_p;

template <class T>
class node
{
public:
	unsigned pos[2];				
	node<T> * p_next[2];	
	T dato;

	node(const int & i, const int & j, node<T> * r_next, node<T> * c_next)
	{
		pos[0] = i; 
		pos[1] = j; 
		p_next[0] = r_next; 
		p_next[1] = c_next; 
	}
	friend class m_p<T>;
};

template <class T>
class m_p
{
private:
	node<T> **index[2];
	unsigned int n_rows;
	unsigned int n_cols; 
 
public:
	m_p(const int & m, const int & n){
		index[0] = new node<T> * [m];
		index[1] = new node<T> * [n];
		n_rows=m;
		n_cols=n;

	}
	~m_p();
	T & operator()(const int & i, const int & j);	
	bool find(node<T> **& n, const int & i, const int & p, const bool & b);
	void print(const bool & b);
	void print2();
	friend ostream & operator << (ostream & os, const m_p<T> & m){
		node<T> * temp;
		for(int i=0;i<m.n_rows;i++){
			temp = m.index[0][i];
			while(temp){
				printf("(%d %d) ", temp->pos[0], temp->pos[1]+1);
				os << temp->dato << " -> ";
				temp = temp->p_next[0];
			}
		}	
	};
};

#include "matrix.inl"
#endif
