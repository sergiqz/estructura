#include "bst.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	bst<int,int> bst;
	/*
	for(int i=1; i<100; i++){
		bst.insert(rand() % 100,i);
	}*/
	
	bst.insert(2,5);
	bst.insert(1,5);
	bst.insert(3,5);
	bst.insert(4,5);

	bst.remove_v2(2);
	
	bst.print();
	return 0;
}