#include <iostream>
#include <thread>
#include <functional>

void f1(int  n) { n = 100; }
void f2(int& n) { n = 100;  }

int main()
{
	int v = 10;
	f1(v);	// call by value - f1이 실행되는 도중에 v 가 파괴되어도
			//				복사본으로 사용하게 되므로 언제나 안전합니다.

	f2(v);	// call by reference - f2가 실행되는 도중 v가 파괴되면
			//				위험 합니다.
			// 그런데, 멀티스레드가 아니므로 v가 파괴될 확율 없습니다.

}
