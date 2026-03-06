#include "BasicString.h"

#define WhiteSpaces " \t\n\r"

namespace BasicLib {
	 std::string ToUpper(const std::string& p_string) {
		 std::string s;
		for (int i = 0; i < p_string.size(); i++) {
			s += toupper(p_string[i]);
		}
		return s;
	}

	 std::string ToLower(const std::string& p_string) {
		 std::string s;
		for (int i = 0; i < p_string.size(); i++) {
			s += tolower(p_string[i]);
		}
		return s;
	}

	 std::string TrimWhitespace(const std::string& p_string) {
		int ss; // starting index of std:: std::string after the whitespaces
		int se; // ending index of std:: std::string before whitespaces
		ss = p_string.find_first_not_of(WhiteSpaces);
		se = p_string.find_last_not_of(WhiteSpaces);
		if (ss == std::string::npos) {
			ss = 0;
			se = -1;
		}
		return p_string.substr(ss, se - ss + 1);
	}

	 std::string ParseWord(const std::string& p_string, int p_index) {
		int ws; // starting index of word
		int we; // ending index of word
		ws = p_string.find_first_not_of(WhiteSpaces);
		while(p_index > 0) {
			p_index--;
			ws = p_string.find_first_of(WhiteSpaces, ws);
			ws = p_string.find_first_not_of(WhiteSpaces,ws);
		}

		we = p_string.find_first_of(WhiteSpaces, ws);

		if (we == std::string::npos) {
			ws = 0;
			we = 0;
		}
		return p_string.substr(ws, we - ws);
	}

	 std::string RemoveWord(const std::string& p_string, int p_index) {
		int ws; // starting index of word
		int we; // ending index of word
		ws = p_string.find_first_not_of(WhiteSpaces);
		while (p_index > 0) {
			p_index--;
			ws = p_string.find_first_of(WhiteSpaces, ws);
			ws = p_string.find_first_not_of(WhiteSpaces,ws);
		}

		we = p_string.find_first_of(WhiteSpaces, ws);
		we = p_string.find_first_not_of(WhiteSpaces,we);

		if (we == std::string::npos) {
			ws = 0;
			we = 0;
		}
		 std::string str = p_string;
		return str.erase(ws, we - ws);
	}

	 std::string SearchAndReplace(const std::string& p_target, const std::string& p_search, const std::string& p_replace) {
		int ws; // starting index of word
		std::string str = p_target;
		ws = str.find(p_search);
		if(ws == std::string::npos) return p_target;
		while (ws != std::string::npos) {
			str.replace(ws, p_search.size(), p_replace);
			ws = str.find(p_search);
		}
		return str;

	}




}