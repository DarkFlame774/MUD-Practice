#include"ThreadLib/ThreadLib.h"
#include<iostream>

void PrintThraed(void* character) {
	char ch = (char)character;
	for (int i = 0; i < 1000; i++) {
		std::cout << ch;
		std::cout.flush();
		ThreadLib::YieldThread();
		Thread_Id t = ThreadLib::getId();
		if(i == 10) ThreadLib::Kill(t);
	}

}

int main() {
	Thread_Id a = ThreadLib::Create(PrintThraed,(void*)'a');
	Thread_Id b = ThreadLib::Create(PrintThraed,(void*)'b');
	ThreadLib::WaitForFinish(b);
	ThreadLib::WaitForFinish(a);
	std::cin.get();
}