#pragma once
#ifdef _WIN32
	#include "Windows.h"
#else
	#include <sys/time.h>
#endif
#include <cstdint>
#include <ctime>


namespace BasicLib{
	int64_t GetTimeMS();
	int64_t GetTimeS();
	int64_t GetTimeM();
	int64_t GetTimeH();
	std::string TimeStamp();
	std::string DateStamp();
	
	
	class Timer {
	public:
		Timer(int64_t p_timepassed = 0);
		void Reset(int64_t p_timepassed = 0);
		int64_t GetMs();
		int64_t GetS();
		int64_t GetM();
		int64_t GetH();
		int64_t GetD();
		int64_t GetY();
	protected:
		int64_t m_intitTime = 0;
		int64_t m_startTime = 0;
	};

}
