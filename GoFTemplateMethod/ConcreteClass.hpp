#pragma once
/********************************************************************************************
* File:			ConcreteClass.hpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Defines a derivation of the abstract class for the GoF Template Method.
*				There can be as many derivations of the abstract class that do something
*				(the primitive operations) a little differently at different stages of the
*				algorithm. This does nothing.
*******************************************************************************************/
#include "AbstractClass.hpp"


class ConcreteClass : public AbstractClass {
private:
	void PrimitiveOperation1() override
	{
	}

	void PrimitiveOperation2() override
	{
	}
};