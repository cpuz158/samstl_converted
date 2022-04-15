#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;				// std::timed_mutex
//std::recursive_mutex m;	// std::timed_recursive_mutex   2회 이상 lock 가능
//std::shared_mutex m;		// std::timed_shared_mutex

int shared_data = 10;

void foo()
{
	m.lock();
	
	// 공유 자원 사용	
	shared_data = 200;

	m.unlock();
}

int main()
{
	std::thread t1(&foo);
	std::thread t2(&foo);

	t1.join();
	t2.join();
}

