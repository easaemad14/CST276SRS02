#pragma once
/********************************************************************************************
* File:			ConcreteStrategy.hpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Defines a derivation of the abstract class for the GoF Strategy Method.
*				There can be as many derivations of the abstract class that do the algorithm
*				a little differently. This does nothing.
*******************************************************************************************/
#include "Strategy.hpp"


class ConcreteStrategy : public Strategy {
private:
	virtual void AlgorithmInterface() override
	{
	}
};