#include <iostream>
#include <chrono>
using namespace std::chrono;

// duration 정의 : 특정 단위의 갯수(tick count)를 표현하는 자료구조
//				  10초 => 1초의 10개
//					   => 1/1000초의 10000개..

int main()
{
	// 1. duration 사용
	std::chrono::duration<int, std::ratio<1, 100>>  d1(2); // 1/100 * 2
	std::chrono::duration<int, std::ratio<1, 1000>> d2(d1);

	std::cout << d2.count() << std::endl; // 20

	// 2. 이제 duration 으로 단위를 나타내는 타입 만들면 됩니다.
	using namespace std::chrono;
	using Meter      = duration<int, std::ratio<1, 1>>;
	using CentiMeter = duration<int, std::ratio<1, 100>>;
//	using KiloMeter  = duration<int, std::ratio<1000, 1>>;
	using KiloMeter  = duration<int, std::kilo>;

	KiloMeter km(3);   // 3km
	CentiMeter cm(km);

	std::cout << cm.count() << std::endl;

	// 3. 시간을 나타내는 단위 - 이미 표준에 아래 처럼 되어 있습니다.
//	using seconds = duration<int, std::ratio<1, 1>>;
//	using minutes = duration<int, std::ratio<60, 1>>;
//	using hours   = duration<int, std::ratio<3600, 1>>;
}





