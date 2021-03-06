/********************************************************************************************
* File:			main.cpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Main prompts the user for dates to test validity against all formats
********************************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <cassert>
#include "DateValidatorDerivations.hpp"
#include "Context.hpp"


using namespace std;

int main()
{
	Context mainContext;
	// TODO: Learn how to use smart pointers
	DateValidatorI18N *ymdValidator = new DateValidatorYMD();
	DateValidatorI18N *dmyValidator = new DateValidatorDMY();
	DateValidatorI18N *mdyValidator = new DateValidatorMDY();
	DateValidatorI18N *ydmValidator = new DateValidatorYDM();
	mainContext.addStrat(ymdValidator);
	mainContext.addStrat(dmyValidator);
	mainContext.addStrat(mdyValidator);
	mainContext.addStrat(ydmValidator);

	string date;
	for (;;) {
		cout << "Please enter a date (\"quit\" to exit): ";
		getline(cin, date);

		if (date.compare("quit") == 0) {
			break;
		}

		mainContext.checkDate(date);
		cout << endl;
	}

    return 0;
}

