#include "bst.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	bst<int,int> bst;
	for(int i=1; i<100; i++){
		bst.insert(rand() % 100,i);
	}
	/*	
	bst.insert(1,5);
	bst.insert(6,5);
	bst.insert(35,5);
	bst.insert(12,5);
	bst.insert(89,5);
	bst.insert(66,5);
	bst.insert(9,5);
	*/
	bst.remove_v2(41);
	
	bst.print();
	return 0;
}