#include <iostream>
#include <stdlib>
double myrand();
using namespace std;



main(){
	cout << myrand() << endl; 
	cout << myrand() << endl;
	
	
	
}

double myrand(){
	
	return rand()/double(RAND_MAX);
	//return float(5)/float(3);
	
	
	
	
	
}
