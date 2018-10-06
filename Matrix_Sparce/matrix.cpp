#include "matrix.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	m_p<int> m(2,2);
	m(0, 0) = 165;
	m(0, 1) = 244;
	m(1, 1) = 786;
	m(1, 2) = 2644;
	cout << m << endl;
	
	return 0;
}