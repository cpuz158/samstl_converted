#include <vector>
#include "show.h"

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	// 1. 아래 코드는 Point 의 디폴트 생성자가 10번 호출되는 코드입니다.
	// 2. Point 디폴트 생성자가 없으면 에러 입니다.
//	std::vector<Point> v(10); 

	// 디폴트 생성자가 없는 타입을 vector에 넣을때는
	// 1. 10개 만들때 복사 초기화 하기 위한 객체를 전달
	Point pt(0, 0);
	std::vector<Point> v1(10, pt); 

	std::vector<Point> v2(10, Point(0,0) );

	std::vector<Point> v3(10, { 0, 0 } ); // C++11 부터는 이 코드도 가능

	// 2. 모든 요소에 초기값을 다르게 하려면
	std::vector<Point> v4 = { Point(0,0), Point(1,1), Point(2,2) };
	std::vector<Point> v5 = { {0,0}, {1,1},{2,2} }; // C++11 부터 가능

	
}



