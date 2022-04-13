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
	std::vector<Point> v6 { {0,0}, {1,1},{2,2} };
	

	// 3. resize 의 경우도 디폴트 생성자가 없으면 주의해야 합니다.
	std::vector<Point> v7(10, { 0,0 } );
//	v7.resize(15);  // 늘어난 5개에 대해서는 생성자 호출이 필요한데.
					// 디폴트 생성자가 없으므로 에러 

	v7.resize(15, { 0, 0 }); // ok
	v7.resize(7); // 줄어든다면 ? 역시 전달해야 합니다.

	//--------------------------------
	// 아래 3개의 코드를 생각해 보세요
	std::vector< std::vector<int> > m1(10);
	std::vector< std::vector<int> > m2(10, 10);
	std::vector< std::vector<int> > m3(10, { 10 });
}



