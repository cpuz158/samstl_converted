#include <iostream>
#include <thread>
#include <mutex>

// 동기화 자원을 사용할때는 직접 "lock/unlock" 을 수행시
// 예외가 발생하는 "deadlock" 의 가능성이 있습니다.

// 생성자/소멸자로 lock을 관리해야 합니다.
template<typename T>
struct lock_guard
{
	T& mtx;

	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()		      { mtx.unlock(); }
};



std::mutex m;	

int shared_data = 10;

void foo()
{
	lock_guard<std::mutex> g(m);
//	m.lock();

	shared_data = 200;

//	m.unlock();
}




int main()
{
	std::thread t1(&foo);
	std::thread t2(&foo);

	t1.join();
	t2.join();
}

