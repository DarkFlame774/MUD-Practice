#include"ThreadLib/ThreadLib.h"
#include "BasicLib/BasicTime.h"
#include<iostream>

ThreadLib::Mutex m;

void PrintThraed(void* character) {
	char ch = (char)character;
	for (int i = 0; i < 200; i++) {
		m.Lock();
		for (int j = 0; j < 50; j++) {
			std::cout << BasicTime::TimeStamp() << " " << ch << "\n";
			std::cout.flush();
		}
		m.Unlock();
	}

}

int main() {
	BasicTime::Timer timer;
	for (int i = 0; i < 100; i++) {
		std::cout << "Hello" << "\n";
	}
	int x = timer.GetMs();
	std::cout <<  x << "\n";
	for (int i = 0; i < 300; i++) {
		std::cout << "Hello" << "\n";
	}
	std::cout << timer.GetMs() << "\n";
	timer.Reset(x);
	for (int i = 0; i < 200; i++) {
		std::cout << "Hello" << "\n";
	}
	std::cout << timer.GetMs() << "\n";

	std::cin.get();
}