//			
//
//
//			This is the Header for the simBox Class.
//
//
//



#ifndef simBox_h
#define simBox_h 

#include <iostream>
class SimBox 
{
public:
	SimBox(int, int, int, int, int, int);
	SimBox();  					// default constructors
	int getX0();					// returns X0
	int getXR();					// returns XR
	int getY0();					// returns Y0
	int getYR();					// returns YR
	int getp0();					// returns P0 
	int getpR();					// returns pR 
	
	int setX0();					// sets the value of X0
	int setXR();					// sets the value of XR
	int setY0();					// sets the value of Y0
	int setYR();					// sets the value of YR
	int setp0();					// sets the value of P0 
	int setpR();					// sets the value of pR 
private:
	int X0;					// Grid marker: x = 0
	int XR;					// Grid marker: x = 10
	int Y0;					// Grid marker: y = 0
	int YT;					// Grid marker: y = 10
	int p0;					// Pressure at line x = 0
	int pR;					// Pressire at line x = 10

};

#endif
