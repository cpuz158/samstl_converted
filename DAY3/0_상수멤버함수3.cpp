#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}

	// 아래 함수는 "상수 멤버 함수"로 할까요 ? 하지 말까요 ?
	bool operator==(const Point& pt) const
	{
		return x == pt.x && y == pt.y;
	}
};

int main()
{
	const Point p1(1, 2);
	const Point p2(1, 2);

	if (p1 == p2) // p1.operator==(p2)
	{
	}
}


