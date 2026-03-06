#include "BasicLib.h"

#ifdef _WIN32
class Win32PerformanceCounter {
public:
	int64_t m_frequency;
	Win32PerformanceCounter() {
		QueryPerformanceFrequency((LARGE_INTEGER*)&m_frequency);
		m_frequency /= 1000;
	}
};
Win32PerformanceCounter g_win32counter;
#endif

namespace BasicLib{

	int64_t GetTimeMS() {
		#ifdef _WIN32
			int64_t t;
			QueryPerformanceCounter((LARGE_INTEGER*)&t);
			int64_t freq = g_win32counter.m_frequency;
			return t = t / freq;
		#else
			struct timeval t;
			int64_t s;
			gettimeofday(&t, 0);
			s = t.tv_sec;
			s *= 1000;
			s += (t.tv_usec / 1000)
				return s;
		#endif
	}

	int64_t GetTimeS() {
		return GetTimeMS() / 1000;
	}

	int64_t GetTimeM() {
		return GetTimeMS() / 1000 / 60;
	}

	int64_t GetTimeH() {
		return GetTimeMS() / 1000 / 60 / 60;
	}

	std::string TimeStamp() {
		time_t t = time(0);
		struct tm time;
		localtime_s(&time, &t);
		char timeBuf[9];
		strftime(timeBuf, 9, "%H:%M:%S", &time);
		return timeBuf;
	}

	std::string DateStamp() {
		time_t t = time(0);
		struct tm time;
		localtime_s(&time, &t);
		char dateBuf[11];
		strftime(dateBuf, 9, "%Y:%m:%d", &time);
		return dateBuf;
	}

	Timer::Timer(int64_t p_timepassed) {
		Reset(p_timepassed);
	}

	void Timer::Reset(int64_t p_timepassed) {
		m_startTime = p_timepassed;
		m_intitTime = GetTimeMS();
	}

	int64_t Timer::GetMs() {
		return (GetTimeMS() - m_intitTime) + m_startTime;
	}

	int64_t Timer::GetS() {
		return GetMs() / 1000;
	}

	int64_t Timer::GetM() {
		return GetMs() / 1000 / 60;
	}

	int64_t Timer::GetH() {
		return GetMs() / 1000 / 60 / 60;
	}

	int64_t Timer::GetD() {
		return GetMs() / 1000 / 60 / 60 / 24;
	}

	int64_t Timer::GetY() {
		return GetMs() / 1000 / 60 / 60 / 365;
	}

}
