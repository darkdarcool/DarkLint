#include <iostream>
#include "./colors.h"

std::string greencolor() {
	return green;
}

std::string resetcolor() {
	return reset;
}

namespace error {
	void error(std::string kind, std::string message, int line) {
		std::cout << redBg << kind << reset << " " << red << message << reset << std::endl; // << blue << "\nLine => " << line << reset << std::endl; 
	}
}