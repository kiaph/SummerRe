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
#include "HDR001/cell.h"

//setting up the constructors

SimBox::SimBox(int pX0)
{
	SimBox::X0 = pX0;
	SimBox::XR = 10; 
	SimBox::Y0 = 0; 
	SimBox::YT = 10; 
	SimBox::p0 = 0; 
	SimBox::pR = 0;
	std::cout << "This is SimBox -1001000" << std::endl;
	
	
}
SimBox::SimBox(int pX0 = 0, int pXR = 10, int pY0 = 0, int pYT = 10, int pp0 = 0, int ppR = 0)
{
	std::cout << "This is SimBox 01001000" << std::endl;
	SimBox::X0 = pX0;
	SimBox::XR = pXR;
	SimBox::Y0 = pY0;
	SimBox::YT = pYT;
	SimBox::p0 = pp0;
	SimBox::pR = ppR;

}
SimBox::SimBox()
{
	//int X0 = 0; int XR = 10; int Y0 = 0; int YT = 10; int p0 = 0; int pR = 0;
	this->X0 = 1;
	this->XR = 10;
	this->Y0 = 0;
	this->YT = 10;
	this->p0 = 0;
	this->pR = 0;

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
