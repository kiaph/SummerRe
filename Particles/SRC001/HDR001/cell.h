//			
//
//
//			This is the Header for the Cell Class.
//
//
//



#ifndef cell_h
#define cell_h 

#include <iostream>
//#include "simBox.h"

class SimBox; // say SimBox exsist

class Cell 
{
public:
	Cell(int,SimBox);
	SimBox* getX0();
	SimBox* getXR();
	SimBox* getY0();
	SimBox* getYT();
	SimBox* getp0();
	SimBox* getpR();
	bool isBoundry();
	bool isEmpty();
	bool isClaimed();
	// Cell(); future call to return information on all available cells.
	

				
private:
	Cellfinder();

};

#endif
