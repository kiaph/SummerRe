//
//	This is the header for the parx class file.
//
//
//
//
#ifndef parxy_h
#define parxy_h 

#include <iostream>
class Parxy 
{
public:
	Parxy(int, int, int, int, int);
	Parxy();  					// default constructors
	int getpX();					// return X position
	int getpY();					// return Y position
	int getpVx();					// return velocity in X
	int getpVy();					// return velocity in Y
	int getpMass();					// return mass value
	
	int setpX(int pXn = 1);				// set X position
	int setpY(int pYn = 1);				// set Y position
	int setpVx(int pVxn = 1);			// set veleocity in X
	int setpVy(int pVyn = 1);			// set velocity in Y
	int setpMass(int pMassn = 1);			// set mass value
private:
	int pX;					// X position element
	int pY;					// Y position element
	int pVx;				// Velocity in direction X elem
	int pVy;				// Velocity in direction Y elem
	int pMass;				// Mass of parcel

};

#endif

	


