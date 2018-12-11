#include "interval.h"
#include <iostream>
#include <fstream>
#include <stdlib.h> 
using namespace std;

int main(){
	intervalTree IT;

	IT.insert(15,20);
	IT.insert(10,30);
	IT.insert(17,19);
	IT.insert(5,20);
	IT.insert(12,15);
	IT.insert(30,40);
	//IT.print();
	IT.overlapSearch(100,500);
	return 0;
}
