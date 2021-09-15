#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>     

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}



namespace utils {
	std::vector<std::string> split(std::string strToSplit,char delimeter) {
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter))
    {
       splittedStrings.push_back(item);
    }
    return splittedStrings;
	};
	bool find(std::string line, std::string sWord) {
		std::string check = line;
		replace(line, sWord, "0");
		if (check == line) {
			return false;
		}
		return true;
	}
}