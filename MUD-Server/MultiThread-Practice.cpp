//#include"ThreadLib/ThreadLib.h"
#include "BasicLib/BasicLib.h"
#include<iostream>

//ThreadLib::Mutex m;
//
//void PrintThraed(void* character) {
//	char ch = (char)character;
//	for (int i = 0; i < 200; i++) {
//		m.Lock();
//		for (int j = 0; j < 50; j++) {
//			std::cout << BasicLib::TimeStamp() << " " << ch << "\n";
//			std::cout.flush();
//		}
//		m.Unlock();
//	}
//
//}

int main() {
	
	std::string str0  = "    Hello My name is Abhinav is very is good is";
	std::string str1  = BasicLib::SearchAndReplace(str0,"is","o");
	 str1  = BasicLib::TrimWhitespace(str1);
	std::string str2  = BasicLib::ToString(123) + " " + str1;
	int str3  = BasicLib::ToType<int>(str2) / 2;
	int str4  = BasicLib::ToType<int>(str2) / 2;
	
	std::cout << str0 << "\n";
	std::cout << str1 << "\n";
	std::cout << str2 << "\n";
	std::cout << str3 << "\n";
	std::cout << str4 << "\n";

	std::cin.get();
}