#include <iostream>
#include <bits/stdc++.h>
#include "rb.h"
using namespace std;
int main(){
	rb<int,int> rb1;


	int iSecret, jSecret;
    srand (time(NULL));


    for(int i=1;i<30;i++){
        iSecret = rand() % 30 + 1;
        rb1.insert(iSecret,jSecret);
        rb1.printARBOL(i);
        
       
    }

/*
    for(int i=31;i<60;i++){
        iSecret = rand() % 30 + 1;
        rb1.remove(iSecret,jSecret);
        rb1.dibujararbol(i);
        cout<<iSecret<<endl;
       
    }
*/
}