#include <iostream>
#include <chrono>
#include <thread>
using namespace std::chrono;
using namespace std::literals; // 3min, 3s 등

int main()
{
	// 1. predefined typedef
	hours		 h(1);		// using hours = duration<int, ratio<3600,1>>;
	minutes      m  = h;	// 
	seconds      s  = h;
	milliseconds ms = h;
	microseconds us = h;
	nanoseconds  ns = h;

	std::cout << h.count() << std::endl;
	std::cout << m.count() << std::endl;
	std::cout << s.count() << std::endl;
	std::cout << ms.count() << std::endl;
	std::cout << us.count() << std::endl;
	std::cout << ns.count() << std::endl;

	// 앞으로 "3초"가 필요하면 아래 처럼 만드세요
	std::chrono::seconds s1(3);



	// 2. literals( h, min, s, ms, us, ns )
	//	   C++11 부터 "user define literal" 이라는 문법이 있습니다.
	
	auto s2 = 10s; // seconds operator""s(10) 이라는 함수 가 호출되는 문법이 있습니다.



	seconds sec = 1min;

	sec = 1min + 3s;
	sec += 40s;
	std::cout << sec.count() << std::endl;

	seconds sec2 = 1min + 3s;
	std::cout << sec2.count() << std::endl;


	// 결론 어떤 함수에 10초를 보내고 싶다.
//	foo(std::chrono::seconds(10)); // seconds 객체를 직접 생성하거나
//	foo(10s); // 이렇게 하면 됩니다.
}
// 3s, 3min 등을 사용하려면
//#include <chrono>				// 이 헤더를 포함하고
//using namespace std::literals;	// 이 namespace 를 열어 주세요