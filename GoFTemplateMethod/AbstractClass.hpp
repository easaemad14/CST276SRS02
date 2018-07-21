#pragma once
/********************************************************************************************
 * File:		AbstractClass.hpp
 * Author:		Easa El Sirgany
 *				easa.elsirgany@oit.edu
 *
 * Description: Defines the abstract class for the GoF Template Method
 *******************************************************************************************/


class AbstractClass {
public:
	void TemplateMethod() {
		// Do some shit
		PrimitiveOperation1();
		// Do something else
		PrimitiveOperation2();
		// Maybe there's more to do?
	}

private:
	virtual void PrimitiveOperation1() = 0;
	virtual void PrimitiveOperation2() = 0;
};
