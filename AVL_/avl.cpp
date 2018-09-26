#include "avl.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){

	avl<int,int> avl;
	
	for(int i=1; i<100; i++){
		avl.insert(i,i);
		avl.print(i);

	}

	//avl.remove(64);
	//avl.print();
	return 0;
}