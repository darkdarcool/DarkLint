#include <iostream>
#include "./utils/utils.h"
#include "./utils/err.h"
#include "./utils/words.h"

;

std::string process(std::string const& s, std::string word)
{
    std::string::size_type pos = s.find(word);
    if (pos != std::string::npos)
    {
        return s.substr(0, pos);
    }
    else
    {
        return s;
    }
}


void lint(std::string code) {
	std::vector<std::string> text = utils::split(code, '\n');
	if (text[0][0] != '\t') {
		error::error("Indentation", "All paragraphs must have indentation to clearly form new paragraphs", 1);	
		return;
	}
	int linenumber = -1;
	for (std::string line: text) {
		linenumber++;
		for (std::string word : words) {
			if (utils::find(line, word)) {
				std::cout << "\n\033[34m_________________________________\033[0m" << std::endl << std::endl;
				error::error("Bad words", "Never use bland words. Using better words can make you look smarter!", linenumber);
				std::string s = process(line, word);
				std::cout << linenumber - 1 << ": " << text[linenumber - 1] << std::endl;
				std::cout << linenumber << ": " << line << std::endl; 
				for(char _e : s) {
    			std::cout << greencolor() << "~";
				}
				std::cout << greencolor() << "~~~^" << resetcolor() << std::endl;
				std::cout << linenumber + 1 << ": " << text[linenumber + 1];
			}
		}
	}
}