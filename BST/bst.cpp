#include "bst.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	bst<int,int> bst;
	for(int i=1; i<45; i++){
		bst.insert(rand() % 100,i);
	}
	bst.print();
	return 0;
}