#include <iostream>
#include "linked_list_pila_cola.h"
#include <ctime>
#include <cstdio>
using namespace std;

int main(){
	//linked_list<int> lista;
	/*lista.insert_front(32);
	lista.insert_front(113);
	lista.insert_front(66);
	lista.insert_front(85);
	lista.insert_front(94);
	//lista.remove_front();
	//lista.remove_back();
	lista.print();*/
	const int N=1000000000;
	int *aint;
	for (int n = 10; n <= N; n*=10)
	{
		float ta=clock();
		aint=new int[n];
		for(int i=0; i<n; i++){
			aint[i]=i*i;
		}
		delete []aint;
		ta=clock()-ta;
		float tl = clock();
		linked_list<int> * lint=new linked_list<int>;
		for(int i=0; i<n; i++){
			lint->insert_front(i*i);
		}
		delete lint;
		tl=clock()-tl;
		printf("%d %.3f %.3f \n", n, ta / CLOCKS_PER_SEC, tl / CLOCKS_PER_SEC);
	}
}