#include <iostream>
#include <memory>
void* operator new(size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}

struct Point
{
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}
};



int main()
{
	// 아래 코드는 동적 메모리 할당을 몇번하게 될까요 ?
	// 2번 : 객체 생성, 관리 객체 생성
//	std::shared_ptr<Point> sp(new Point(1, 2));


	// make_shared<T> : T 타입객체와 관리객체를 한번에 메모리할당해달라
	//					sizeof(T) + sizeof(관리객체) 를 한번에 할당
	std::shared_ptr<Point> sp = std::make_shared<Point>(1, 2);
							// 1. sizeof(Point) + sizeof(관리객체)를 한번에 할당후
							// 2. 해당 메모리를 가리키는 shared_ptr을 만들어서 반환
	
	
}











void foo( std::shared_ptr<int> sp, int n) {}

int goo() { return 10; }

