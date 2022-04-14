#include "show.h"
#include <set>


// set 에 사용자 정의 타입을 넣으려면
// ==> 크기 비교가 가능해야 한다.
// 방법 1. 타입이 "<" 연산이 가능하도록 연산자 재정의 함수 제공
//        => 꼭, 상수 멤버 함수 로 만드세요
//        => 일반적으로는 < 를 만들면 <=, >, >=, ==, != 등도 제공하는것이 좋습니다.
//        => C++20 부터 "<=>" 는 이 연산자를 한개만 만들면 6개 비교연산자 자동지원
// 
// 방법 2. Point 객체 2개를 크기 비교할수 있는 함수 객체를 만들어서 
//        set 의 2번째 템플릿 인자로 전달

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) {}

//	bool operator<(const Point& pt) const  {	return x < pt.x;	}
};

struct PointCompare
{
	bool operator()(const Point& p1, const Point& p2) const
	{
		return p1.x < p2.x;
	}
};

int main()
{
//	std::set<Point> s;  // 이 경우는 비교시 "less" 사용
						// less는 결국 "<" 사용하므로 Point 자체가 < 가능해야함

	std::set<Point, PointCompare> s; // Point 자체가 < 연산이 되지 않아도
									// 상관 없음.
									// Point 2개 비교시 PointCompare 객체사용


	s.insert(Point(5, 5)); 
	s.emplace(3, 2);
	s.emplace(2, 1);
	s.emplace(1, 5);

}










