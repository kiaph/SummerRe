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
class Cell;
class SimBox
{
public:
	SimBox(int, int, int, int, int, int);
	SimBox(int);
	SimBox();  					// default constructors
	int getX0();					// returns X0
	int getXR();					// returns XR
	int getY0();					// returns Y0
	int getYT();					// returns YT
	int getp0();					// returns P0 
	int getpR();					// returns pR 
	
	int setX0(int);					// sets the value of X0
	int setXR(int);					// sets the value of XR
	int setY0(int);					// sets the value of Y0
	int setYT(int);					// sets the value of YT
	int setp0(int);					// sets the value of P0 
	int setpR(int);					// sets the value of pR 
private:
	int X0;					// Grid marker: x = 0
	int XR;					// Grid marker: x = 10
	int Y0;					// Grid marker: y = 0
	int YT;					// Grid marker: y = 10
	int p0;					// Pressure at line x = 0
	int pR;					// Pressire at line x = 10

};

#endif
