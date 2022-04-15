
#include <vector>
#include <algorithm>
#include "show.h"
class Point
{
public:
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}

	~Point() {  }

	void dump() const 	{	std::cout << x << ", " << y << std::endl;	}

	inline bool operator<(const Point& p) const
	{
		return x < p.x;
	}
};

int main()
{
	std::vector<Point> v;

	v.emplace_back(1, 2); // Point(1,2)
	v.emplace_back(2, 3);
	v.emplace_back(3, 2);
	v.emplace_back(0, 1);

	// 핵심 : 1. 사용자 정의 타입을 컨테이너에 넣는것은 문제 없습니다.
	// 
	// 2. 그런데, 일부 알고리즘 적용시 알고리즘이 요구하는 연산을 잘생각하세요

	// sort 할려면 Point 타입의 객체 2개에 대한 크기 비교가 가능해야 합니다.
//	std::sort(std::begin(v), std::end(v)); // error

	// 방법 1. sort 의 마지막 인자로 Point 2개를 비교하는 조건자 전달
//	std::sort(std::begin(v), std::end(v), 
//		[](const Point& p1, const Point& p2) { return p1.x < p2.x; });

	// 방법 2. Point 타입 안에 "operator<()" 를 만들어서 크기 비교가 가능하도록
	Point p1(1, 2);
	Point p2(1, 2);
	bool b = p1 < p2;

	std::sort(std::begin(v), std::end(v)); // ok.. < 가능하므로

}




