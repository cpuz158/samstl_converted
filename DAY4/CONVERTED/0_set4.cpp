// equality, Equivalency
#include "show.h"
#include <set>
#include "debug_alloc.h"

/*
// set find 의 원리
if (root < findelem) // 정확히는 less 객체 사용
	move left child;
else if (findelem < root )
	move right child
else 
	같다고 확인.. 

// 즉, s.find 의 원리는 == 로 검색이 아니라
// 크지도 않고, 작지도 않으면 "찾았다" 라고 판단합니다. - Equivalency
*/


struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	bool operator<(const Point& pt) const  { return x < pt.x;}
};

int main()
{
	std::set<Point> s;  

	s.emplace(3, 2); // Point(3,2)	
	s.emplace(2, 1); // Point(2,1)	
	s.emplace(1, 5); // Point(1,5)	

//	s.emplace(2, 5); // 실패, 현재 < 연산자는 x만 사용하므로..
					// x 값이 2인 것은 이미 (2,1) 이 있으므로

	Point pt(3, 0);

	auto ret = s.find(pt);	// s.find(Point(3,2)) 처럼 해도 됩니다.
							// 현재  이 코드가 왜 에러가 없을까요 ?
							// 검색하려면 == 가 필요하지 않을까요 ?

	if (ret == s.end())
		std::cout << "검색실패" << std::endl;
	else 
		std::cout << "검색성공 : " << ret->x << ", " << ret->y << std::endl;

	// 알고리즘 find 는 "==" 연산으로 검색합니다. - equality 
	auto ret2 = std::find(s.begin(), s.end(), pt); // error
											// Point 는 "==" 연산이 안됩니다

	// s.find    : 크지도 않고 작지도 않으면 "같다" - equivalency
	// std::find : == 로 검색 - equality
}


















