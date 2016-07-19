//
//	This is the parx class file
//
//
//
//
//


#include <iostream>
#include <stdlib.h>
#include "HDR001/parxy.h"

Parxy::Parxy(int pX = 1,int pY = 1,int pVx = 1,int pVy = 1,int pMass = 1)
{
	std::cout << "Does this work" << std::endl;
//First constructor with userdefined values
}


Parxy::Parxy()	
{
	int pX = 1; int pY = 1; int  pVx = 1; int pVy = 1; int pMass = 1;
	std::cout << "Does this work as well?" << std::endl;
//Second constructor with predefined values
}


//defining the get<element> return calls
int Parxy::getpX() {return pX;}
int Parxy::getpY() {return pY;}
int Parxy::getpVx() {return pVx;}
int Parxy::getpVy() {return pVy;}
int Parxy::getpMass() {return pMass;}

//defining the set<element> function calls

int Parxy::setpX(int pXn)
{
	pX = pXn;
	return pX;
}
int Parxy::setpY(int pYn)
{
	pY = pYn;
	return pY;
}
int Parxy::setpVx(int pVxn)
{
	pVx = pVxn;
	return pVx;
}
int Parxy::setpVy(int pVyn)
{
	pVy = pVyn;
	return pVy;
}
int Parxy::setpMass(int pMassn)
{
	pMass = pMassn;
	return pMass;
}





