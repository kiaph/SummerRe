//
//
//		This is the class file for the class simBox
//
//
//
//
//


#include <iostream>
#include <stdlib.h>
#include "HDR001/simBox.h"

//setting up the constructors

SimBox::SimBox(int X0 = 0, int XR = 10, int Y0 = 0, int YR = 10, int p0 = 0, int pR = 0)
{
	std::cout << "This is SimBox 01001000" << std::endl;
}
SimBox::SimBox()
{
	int X0 = 0; int XR = 10; int Y0 = 0; int YR = 10; int p0 = 0; int pR = 0;	
	std::cout << "This is SimBox ------" << std::endl;
}

	int getX0();					
	int getXR();					
	int getY0();					
	int getYR();					
	int getp0();					
	int getpR();
				 
	
	int setX0();					
	int setXR();					
	int setY0();					
	int setYR();					
	int setp0();					 
	int setpR();					
