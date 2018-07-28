/********************************************************************************************
* File:			DateValidator.cpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Naive class to validate date based off of some enumeration
*******************************************************************************************/
#include "stdafx.h"
#include <cassert>

#include "DateValidator.hpp"

using namespace std;


// Get value from private member, checking for Leap year
int DateValidatorI18N::getDaysInMonthBaseOne(int month)
{
	if (!isValidMonth()) { // We are dependant upon the month
		return false;
	}

	auto retVal = daysPerMonth.at(month - 1);
	return (isLeapYear() && (month == 2)) ? ++retVal : retVal;
}

// Algorithm doesn't seem too complex
bool DateValidatorI18N::isLeapYear()
{
	// https://en.wikipedia.org/wiki/Leap_year#Algorithm
	return (mYear % 4) ? false :
		(mYear % 100) ? true :
		(mYear % 400) ? false : true;
}

// Any positive value is good with me
bool DateValidatorI18N::isValidYear()
{
	return (mYear > 0) ? true : false;
}

// Do I really need to explain this?
bool DateValidatorI18N::isValidMonth()
{
	return ((mMonth > 0) && (mMonth < 13)) ? true : false;
}

// This gets a little trickier...
bool DateValidatorI18N::isValidDay()
{
	return ((mDay > 0) && (mDay <= getDaysInMonthBaseOne(mMonth))) ? true : false;
}

// Take a string, parse a date via deliminator (or EOL), and truncate string
// std::atoi will return 0 on failure (if it can't convert); this will break validity
int DateValidatorI18N::getDateValFromString(string & str)
{
	auto retVal = atoi(str.c_str());

	auto pos = str.find_first_of(delims);
	if (pos != string::npos) { // Don't throw out_of_range
		str = str.substr(pos + 1);
	}

	return retVal;
}

// Parse the date according to the format, and check for validity
bool DateValidatorI18N::operator()(const string date, const Format form)
{
	if (date.empty()) {
		return false;
	}

	string tmp(date); // Give us a mutable variable
	switch (form) {
	case Format::DMY:
		mDay = getDateValFromString(tmp);
		mMonth = getDateValFromString(tmp);
		mYear = getDateValFromString(tmp);	
		break;
	case Format::MDY:
		mMonth = getDateValFromString(tmp);
		mDay = getDateValFromString(tmp);
		mYear = getDateValFromString(tmp);
		break;
	case Format::YMD:
		mYear = getDateValFromString(tmp);
		mMonth = getDateValFromString(tmp);
		mDay = getDateValFromString(tmp);
		break;
	case Format::YDM: // Added an extra case for Gregorian YDM
		mYear = getDateValFromString(tmp);
		mDay = getDateValFromString(tmp);
		mMonth = getDateValFromString(tmp);
		break;
	default: // WTF, this isn't possible!
		return false;
	}

	return isValidYear() && isValidMonth() && isValidDay();
}
