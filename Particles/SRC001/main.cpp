//
	//	This is a Test Main
	//
//
//
//
//
//
//


#include <iostream>
#include <stdlib.h>
#include "./HDR001/parxy.h"
#include "./HDR001/simBox.h"


main()
{

	std::cout << "Testing value for pVx" << std::endl;
	std::cout << "Testing a SimBox Value" << std::endl;
	SimBox TheObjectofSimBox = SimBox();
	std::cout << TheObjectofSimBox.getX0() << std::endl;
	TheObjectofSimBox.setX0(3);
	std::cout << TheObjectofSimBox.getX0() << std::endl;
	SimBox NewTestObject = SimBox(9);
	std::cout << NewTestObject.getX0() << std::endl;
	SimBox nine = SimBox(5);
	std::cout << TheObjectofSimBox.getX0() << std::endl;
	std::cout << nine.getX0() << std::endl;
	nine.setX0(2);
	std::cout << nine.getX0() << std::endl;
	



};

