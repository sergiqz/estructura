#include "rb.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){

	rb<int,int> rb;
	for (int i = 1; i < 11; ++i)
	{
		rb.insert(i,i);
		rb.printARBOL(i);
	}
		/*rb.insert(1,1);
		rb.insert(2,1);
		rb.insert(3,1);
		rb.insert(4,1);*/
	
	return 0;
}