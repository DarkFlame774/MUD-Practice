#pragma once
#include <sstream>
#include <string>
#include <cctype>


namespace BasicLib {
	std::string ToUpper(const std::string& str);
	std::string ToLower(const std::string& str);
	std::string TrimWhitespace(const std::string& str);
	std::string ParseWord(const std::string& str,int p_index);
	std::string RemoveWord(const std::string& str, int p_index);
	std::string SearchAndReplace(const std::string& p_target, const std::string& p_search, const std::string& p_replace);

	template <class DataType>
	inline std::string ToString(const DataType& p_data) {
		std::stringstream str;
		str << p_data;
		return str.str();
	}

	template <class DataType>
	inline DataType ToType(const std::string& p_string) {
		std::stringstream str;
		str << p_string;
		DataType datatype;
		str >> datatype;
		return datatype;
	}
}
