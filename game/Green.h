#pragma once
#include "Base.h"
class Green :
	public Base
{
	Result compare(Base& base) {
		std::string name = typeid(base).name();

		if (name == "class Green") {
			base.setResult(Result::Equal);
		}
		else if (name == "class Red") {
			base.setResult(Result::Lose);
		}
		else if (name == "class DarkRed") {
			base.setResult(Result::Win);
		}
		else if (name == "class Blue") {
			base.setResult(Result::Win);
		}
		return getResult();
	}
};

