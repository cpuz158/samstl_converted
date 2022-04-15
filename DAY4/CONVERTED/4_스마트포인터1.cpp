#include <iostream>

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
	~Car()    { std::cout << "~Car" << std::endl; }
};

// 스마트 포인터란 ?
// 개념 : 임의의 객체가 다른 타입의 포인터 역활을 하는 것
// 
// 원리 : -> 와 * 연산자를 재정의 해서 포인터 처럼 보이게 만든것
// 
// 장점 : raw pointer 가 아닌 "객체"라는 점.!
//       생성/복사/대입/파괴의 모든 순간에 해당하는 함수가 호출되고
//		 다양한 기능을 추가할수 있다.
//		 대표적인 활용 예제가 "소멸자에서 객체의 삭제" 지원

// 아래 코드가 핵심 입니다.
class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}

	~Ptr() { delete obj; }

	Car* operator->() { return obj; }
	Car& operator*() { return *obj; } // 참조리턴해야 합니다.
};

int main()
{
	// Ptr 타입의 "객체 p" 가 "Car 타입의 포인터" 처럼 사용됩니다.
	// 1. 아래 코드 원리(메모리 그림 그려 보세요)
	Ptr p = new Car; // Ptr p(new Car)


	// 2. 아래 코드는 원리 생각해 보세요
	p->Go(); // p.operator->()Go() 의 모양인데
			 // (p.operator->())->Go()로 해석됩니다.

	(*p).Go(); // p.operator*() 도 필요 합니다.


	std::cout << sizeof(p) << std::endl; // 현재소스는 raw pointer 크기와 동일
	std::cout << sizeof(Car*) << std::endl;
}


