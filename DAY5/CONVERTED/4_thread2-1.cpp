#include <iostream>
#include <thread> 

void foo(int n, double d)
{
	std::cout << "foo" << std::endl;
}

int main()
{
	std::thread t1(&foo, 3, 3.4);

	// 스레드를 생성한후에는 반드시 아래 작업중 한개를 해야 합니다.
//	t1.join();   // 스레드 종료를 대기
	t1.detach(); // 스레드 종료를 대기하지 않고, 더이상 핸들도 필요 없다.

	// .....
}



