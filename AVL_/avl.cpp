#include "avl.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){

	avl<int,int> avl;
	
	for(int i=1; i<50; i++){
		avl.insert(i,i);
		//avl.print(i);
		//avl.print2();
		avl.printOficial(i);
	}
	//avl.print3(1);
	//avl.print(1);
	//avl.remove(64);
	//avl.print();
	return 0;
}