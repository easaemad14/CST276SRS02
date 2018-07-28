/********************************************************************************************
* File:			Context.cpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Context class from the GoF Strategy Pattern and almost factory
*******************************************************************************************/
#include "stdafx.h"
#include <iostream>
#include "Context.hpp"

using namespace std;


// Remove all strategies
Context::~Context()
{
	for (auto s : stratFact) {
		delete s;
	}
}

// Add a strategy to our vector
void Context::addStrat(DateValidatorI18N *newStrat)
{
	if (newStrat != nullptr) {
		stratFact.push_back(newStrat);
	}
}

// Check the date for all strategies
void Context::checkDate(const string date)
{
	for (auto s : stratFact) {
		if (s->is_good(date)) {
			cout << date << " is a valid date for strategy " <<
				s->getStratName() << endl;
		}
	}
}