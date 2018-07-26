#pragma once
/********************************************************************************************
* File:			DateValidator.hpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	C++ header containing all goodies for DateValidator.cpp
*******************************************************************************************/
#include <string>
#include <vector>


class DateValidatorI18N {
public:
	enum class Format { YMD, DMY, MDY };
	bool operator()(const std::string date, const Format form);
	int getDaysInMonthBaseOne(int month);

private:
	bool isLeapYear();
	bool isValidYear();
	bool isValidMonth();
	bool isValidDay();

private:
	const std::string delims{ " /-." };
	int mDay, mMonth, mYear;
	const std::vector<int> daysPerMonth{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int getDateValFromString(std::string &str);
};