#include <vector>
#include "show.h"

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) 
	{
		std::cout << "Point()" << std::endl;
	}
	~Point() { std::cout << "~Point()" << std::endl; }
	
	Point(const Point& p)
	{
		std::cout << "Point(const Point&)" << std::endl;
	}
};
int main()
{
	std::vector<Point> v;

	// 실행결과 예측해 보세요
	// 1. 객체를 생성후 넣기.
//	Point pt(1, 2);
//	v.push_back(pt); 


	// 2. 임시객체로 전달
	// 이경우도 객체가 2개 이므로, 소멸자가 2번 호출
	// 단, 임시객체이므로 아래 문장이 끝나면 바로 파괴
//	v.push_back( Point(1, 2) );  

	// 3. {1,2} 도 역시 임시객체 생성 입니다.
//	v.push_back( { 1,2 } ); // Point{1,2} 즉 Point(1,2) 와 동일


	// 4. 임시객체의 생성이 아닌, 
	//    객체를 만들기 위한 생성자 인자를 전달
	v.emplace_back(1, 2); // {1,2} 가 아닌 2개의 인자 입니다.
						  // new Point(1,2) 로 만들어 달라는 것


	std::cout << "------------------" << std::endl;	
}

// 핵심 
// 1. 컨테이너가 "사용자 정의 타입을 값" 으로 보관하는 경우
// push_xxx() 보다 emplace_xxx() 가 좋습니다.

// 2. 단, int 타입이나, 사용자정의 타입의 포인터(Point*)를 보관하는 경우는
// 그냥, push_xxx() 로 넣어도 됩니다. emplace_xxx() 도 사용가능

