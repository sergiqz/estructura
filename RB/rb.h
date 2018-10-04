#ifndef RB_H
#define RB_H
#include <iostream>
#include <fstream>
using namespace std;

enum color_t: bool {BLACK = 0, RED = 1};

template <class K, class D>
class rb;

template <class K, class D>
class node
{
    private:
        K key;
        D data;
        node<K,D> *p_child[2];
        color_t color;
        int hgt;
  
    
    public:
        node();
        ~node();
        node(const K & _key, const D & _data);
    friend class rb<K,D>;
};



template <class K, class D>
class rb
{
    private:
        node<K,D> * root;
    public:
        rb();
        ~rb();
        node<K,D>* insert (const K & key,const D & data, node<K,D> ** n, node<K,D> ** p);
        bool insert(const K & key,const D & data) ;
        node<K,D>* remove (const K & key,const D & data, node<K,D> ** n, node<K,D> ** p);
        bool remove(const K & key,const D & data) ;
        void fixRedblack(node<K,D> **n,node<K,D> **p,bool child,node<K,D> *aux);
        color_t getColor(node<K,D> *&n);
        void setColor(node<K,D> *&n, color_t color);
        int max(int a,int b);
        int altura(node<K,D> * n);
        int altura();
        void printARBOL(ofstream & es,node<K,D> *n);
        void printCOLOR(ofstream & es,node<K,D> *ptr);
        void printARBOL(int num);
        bool find(node<K,D> *n,int a);
        bool turnSide(node<K,D> **n, bool side);
        void rotar(node<K,D>** n, bool side);
        bool balance(node<K,D> **n,bool child);
        node<K,D>* Min(node<K,D> **n);


    private:
        bool draw(node<K,D> *n, ofstream & os);
};

#include "rb.inl"
#endif