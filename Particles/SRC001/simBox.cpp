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

SimBox::SimBox(int X0 = 0, int XR = 10, int Y0 = 0, int YT = 10, int p0 = 0, int pR = 0)
{
	std::cout << "This is SimBox 01001000" << std::endl;
}
SimBox::SimBox()
{
	int X0 = 0; int XR = 10; int Y0 = 0; int YT = 10; int p0 = 0; int pR = 0;	
	std::cout << "This is SimBox ------" << std::endl;
}

	int SimBox::getX0(){return X0;}				
	int SimBox::getXR(){return XR;}					
	int SimBox::getY0(){return Y0;}					
	int SimBox::getYT(){return YT;}			
	int SimBox::getp0(){return p0;}					
	int SimBox::getpR(){return pR;}
				 
	
	int SimBox::setX0(int pX0)
	{
	
		X0 = pX0;
		return X0;
	}
						
	int SimBox::setXR(int pXR)
	{
		XR = pXR;
		return XR;
	}					
	int SimBox::setY0(int pY0)
	{
	
		Y0 = pY0;
		return Y0;
	}					
	int SimBox::setYT(int pYT)
	{
	
		YT = pYT;
		return YT;
	}					
	int SimBox::setp0(int pp0)
	{
	
		p0 = pp0;
		return p0;
	}					 
	int SimBox::setpR(int ppR)
	{
	
		pR = ppR;
		return pR;
	}					
