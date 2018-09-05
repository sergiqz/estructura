#include <iostream>
#include "linked_list_pila_cola.h"
using namespace std;

template <class T>
class linked_list;

template <class T>
nodo<T>::nodo(const T & d, nodo<T> *next){
	dato=d;
	p_next=next;
}

template <class T>
void nodo<T>::print(){
	cout<<dato<<"->";
}

template <class T>
linked_list<T>::linked_list(){
	sn=new nodo<T>[100000];
	p_head=NULL;
	p_last=NULL;
}

template <class T>
void linked_list<T>::insert_front(const T & d){
	p_head=new nodo<T>(d,p_head);
	if(p_head->p_next==NULL){
		p_last=p_head;
	}
}

template <class T>
void linked_list<T>::insert_front_2(const T & d){
	int idxfree=0;
	aux=&sn[idxfree++];
	aux->dato=d;
	if(p_head==NULL){
		p_head=aux;
		aux->p_next=NULL;
	}
	else{
		aux->p_next=p_head;
		p_head=aux;
	}
}

template <class T>
void linked_list<T>::insert_back(const T & d){
	p_last->p_next=new nodo<T>(d);
	p_last=p_last->p_next;
}

template <class T>
void linked_list<T>::remove_front(){
	if(!p_head) return;
	nodo<T> *temp=p_head;
	p_head=p_head->p_next;
	delete temp;
}

template <class T>
void linked_list<T>::remove_back(){
	nodo<T> *temp=p_head;
	nodo<T> *temp2=temp->p_next;
	p_head=temp->p_next;
}

template <class T>
void linked_list<T>::print(){
	nodo<T> *temp=p_head;
	while(temp){
		temp->print();
		temp=temp->p_next;
	}
}

template <class T>
void cola<T>::push_cola(const T & d){
	insert_back(d);
}

template <class T>
void cola<T>::pop_cola(){
	delete linked_list<T>::p_head->dato;
}

template <class T>
void pila<T>::push_pila(const T & d){
	insert_front(d);
}

template <class T>
void pila<T>::pop_pila(){

}