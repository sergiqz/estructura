#include "avl.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){

	avl<int,int> avl;
	/*
	for(int i=1; i<100; i++){
		avl.insert(i,i);
	}*/
	

	avl.insert(1,5);
	avl.insert(4,5);
	//avl.insert(10,5);
	//avl.insert(8,5);
	//avl.insert(12,5);
	//avl.insert(6,5);

	//avl.print();
	//bst.remove_v2(2);
	
	avl.print();
	return 0;
}