#include <iostream>

// C++11의 스마트포인터를 사용하려면 필요한 헤더
#include <memory>

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
};

int main()
{
	// 핵심 1. 표준 스마트 포인터 이름은 "shared_ptr" 입니다.
	std::shared_ptr<int> p1(new int);   // ok
//	std::shared_ptr<int> p2 = new int;  // error. 
										// 생성자 앞에 explicit 를 붙이면 () 초기화만
										// 가능합니다.


	// 핵심 2. 스마트 포인터의 크기
	//        구현에 따라 달라 질수 있지만 대부분 "raw pointer 크기의 2배"
	std::cout << sizeof(p3)   << std::endl; // ?
	std::cout << sizeof(int*) << std::endl; // ?



	
	// 핵심 3. -> 와 . 연산자
	std::shared_ptr<Car> sp1(new Car);
	std::shared_ptr<Car> sp2 = sp1;


	// -> : 대상체(Car) 의 멤버에 접근
	sp1->Go(); // Car 의 멤버 함수

	// . : shared_ptr 자체의 멤버 함수
	int n = sp1.use_count();

	std::cout << n << std::endl; // 참조계수 2

	Car* p = sp1.get();
	
	sp1.reset(); // 
	sp1 = 0;
	sp1 = nullptr;
}



