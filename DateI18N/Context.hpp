#pragma once
/********************************************************************************************
* File:			Context.hpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Context class from the GoF Strategy Pattern. This almost looks like a
*				factory, but the GoF pattern is a little more specific about what a factory
*				looks like....
*******************************************************************************************/
#include <vector>
#include "DateValidator.hpp"


class Context {
public:
	~Context();
	void addStrat(DateValidatorI18N *newStrat);
	void checkDate(const std::string date);

private:
	std::vector<DateValidatorI18N *> stratFact;
};