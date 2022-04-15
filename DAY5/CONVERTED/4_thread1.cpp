#include <iostream>

// C++11 부터 스레드 관련 클래스 지원.
#include <thread> 
#include <chrono>
//using namespace std::literals;

// this_thread namespace 
// => 4개의 간단한 함수 제공
int main()
{
	std::cout << std::this_thread::get_id() << std::endl;

	// 스레드를 재우려면 인자로 "chrono" 라이브러리 의 시간이 전달되어야 합니다
//	std::this_thread::sleep_for(3s);
	std::this_thread::sleep_for(std::chrono::seconds(3) );

	std::this_thread::sleep_for(std::literals::operator""s(3));

//	std::this_thread::sleep_until(이때까지); // xtime 구조체 형태로 전달.

//	std::this_thread::yield(); // 현재 스레드의 남은 실행시간 포기하고
								// 다른 스레드 실행

}


