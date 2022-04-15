#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
using namespace std::chrono;

// system_clock : 현재 시간을 얻을때 사용하는 클래스, non monotonic clock
// time_point   : 시간의 시작점과 duration<>을 보관하는 클래스
//				  ex) epoch time : 1970년 1월 1일 기준 16880 시간 경과
					

int main()
{
	// 1. 현재 시간을 얻는 방법
	system_clock::time_point tp = system_clock::now();



	// 2. time_point => duration 얻어내기... 정밀도가 낮아지는 경우 명시적 캐스팅 필요..
	// 아래 코드는 "1970년 1월 1일 자정"을 기준으로 몇 "nanosec" 가 지났는지 구하는 코드
	nanoseconds nanosec = tp.time_since_epoch();

	seconds     sec     = duration_cast<seconds>(tp.time_since_epoch());

	std::cout << nanosec.count() << std::endl;
	std::cout << sec.count() << std::endl;

	// days 는 C++20 부터 추가될 예정입니다.
	// 그 전에 필요 하면 아래 처럼 만들면 됩니다.
	using days = duration<int, std::ratio<60 * 60 * 24>>;

	std::cout << (duration_cast<days>(tp.time_since_epoch())).count() << std::endl;


	
	// 3. time_point => 칼린더 형태의 날짜로 변경하기
	time_t t = system_clock::to_time_t(tp); // 1. time_point => struct time_t
	std::string s = ctime(&t);					// 2. struct time_t => char*
	std::cout << s << std::endl;
	
}



