#pragma once
/********************************************************************************************
* File:			Context.hpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Defines the context class for the GoF Strategy Method; doesn't do anything
*******************************************************************************************/
#include "Strategy.hpp"


class Context {
public:
	void ContextInterface()
	{
	}

private:
	Strategy *mStrat; // Only room for one concrete strategy at a time
};