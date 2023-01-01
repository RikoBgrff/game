#pragma once
#include "Base.h"
class Red :
	public Base
{
public:
	Result compare(Base& base) {
		std::string name = typeid(base).name();

		if (name == "class Red") {
			base.setResult(Result::Equal);
		}
		else if (name == "class Blue") {
			base.setResult(Result::Lose);
		}
		else if (name == "class DarkRed") {
			base.setResult(Result::Lose);
		}
		else if (name == "class Green") {
			base.setResult(Result::Win);
		}
		return getResult();
	}
};

