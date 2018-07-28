#pragma once
/********************************************************************************************
* File:			DateValidator.hpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Date Validator using the GoF Strategy Pattern. The DateValidator represents
*				the abstract Strategy class.
*******************************************************************************************/
#include <string>
#include <vector>


class DateValidatorI18N {
public:
	virtual bool is_good(const std::string date) = 0;
	virtual std::string getStratName() = 0;

protected:
	void setDay(const int day) { mDay = day; }
	void setMonth(const int month) { mMonth = month; }
	void setYear(const int year) { mYear = year; }
	int getDateValFromString(std::string &str);
	bool isLeapYear();
	bool isValidYear();
	bool isValidMonth();
	bool isValidDay();
	int getDaysInMonthBaseOne(int month);

private:
	const std::string delims{ " /-." };
	int mDay, mMonth, mYear;
	const std::vector<int> daysPerMonth{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
};