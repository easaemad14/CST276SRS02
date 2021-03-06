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
#include "DateValidator.hpp"


using namespace std;

int main()
{
	DateValidatorI18N valid;
	string date;

	for (;;) {
		cout << "Please enter a date (\"quit\" to exit): ";
		getline(cin, date);

		if (date.compare("quit") == 0) {
			break;
		}

		if (valid(date, DateValidatorI18N::Format::YMD)) {
			cout << date << " is a valid YMD" << endl;
		}

		if (valid(date, DateValidatorI18N::Format::DMY)) {
			cout << date << " is a valid DMY" << endl;
		}

		if (valid(date, DateValidatorI18N::Format::MDY)) {
			cout << date << " is a valid MDY" << endl;
		}

		// Added a new test case for Latvia, Nepal, and Terkmenistan
		if (valid(date, DateValidatorI18N::Format::YDM)) {
			cout << date << " is a valid YDM" << endl;
		}

		cout << endl;
	}

    return 0;
}

