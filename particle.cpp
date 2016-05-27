#include <iostream.h>
#include <stdlib.h>
double myrand();


main(){
	cout << myrand() << endl; 
	cout << myrand() << endl;
	
	
	
}

double myrand(){
	
	return rand()/double(RAND_MAX);
	//return float(5)/float(3);
	
	
	
	
	
}