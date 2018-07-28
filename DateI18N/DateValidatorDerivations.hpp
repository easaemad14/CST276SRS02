#pragma once
/********************************************************************************************
* File:			DateValidatorDerivations.hpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	All variations (derived classes) of the date validator are all contained in
*				this file (because they are small and it is easy to see the differences.
*******************************************************************************************/
#include <string>
#include "DateValidator.hpp"


class DateValidatorYMD : public DateValidatorI18N {
	bool is_good(const std::string date) override
	{
		if (date.empty()) {
			return false;
		}

		std::string tmp(date); // Get a mutable type
		setYear(getDateValFromString(tmp));
		setMonth(getDateValFromString(tmp));
		setDay(getDateValFromString(tmp));

		return isValidYear() && isValidMonth() && isValidDay();
	}

	std::string getStratName() override
	{
		//return "DateValidatorYMD"s;
		return std::string("DateValidatorYMD");
	}
};

class DateValidatorDMY : public DateValidatorI18N {
	bool is_good(const std::string date) override
	{
		if (date.empty()) {
			return false;
		}

		std::string tmp(date);
		setDay(getDateValFromString(tmp));
		setMonth(getDateValFromString(tmp));
		setYear(getDateValFromString(tmp));

		return isValidYear() && isValidMonth() && isValidDay();
	}

	std::string getStratName() override
	{
		return std::string("DateValidatorDMY");
	}
};

class DateValidatorMDY : public DateValidatorI18N {
	bool is_good(const std::string date) override
	{
		if (date.empty()) {
			return false;
		}

		std::string tmp(date);
		setMonth(getDateValFromString(tmp));
		setDay(getDateValFromString(tmp));
		setYear(getDateValFromString(tmp));

		return isValidYear() && isValidMonth() && isValidDay();
	}

	std::string getStratName() override
	{
		return std::string("DateValidatorMDY");
	}
};