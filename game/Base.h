#pragma once
#include <iostream>
#include "Result.h"
class Base
{
private:
	Result result;
public:
	Base() :result() {}

	virtual	Result compare(Base& base) = 0;

	void setResult(Result result) {
		if (result >= 0 && result <= 2) {
			this->result = result;
		}
		else {
			std::cout << "Result must be 0,1 or 2" << std::endl;
		}
	}

	Result getResult() {
		return result;
	}
};

