// 1. github.com/codenuri/samstl 에서 "DAY3_사전소스.zip" 받으시면 됩니다.
// 2. codexpert.org 에서 출석해주세요
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	// 핵심 : 상수 객체는 상수 멤버 함수만 호출할수 있다.
	//       멤버 함수를 만들때, 객체의 상태를 변경하지 않은 멤버함수라면
	//		 반드시 상수 멤버함수로 해야 한다.
	void print() const
	{
//		x = 10; // error. 상수 멤버 함수에서는 멤버 데이타를 수정할수 없다.

		std::cout << x << ", " << y << std::endl;
	}
};
int main()
{
//	Point pt(1, 2);
	const Point pt(1, 2);

//	pt.x = 10;		// error. x 는 public 에 있지만, 상수 이므로
//	pt.set(10, 20);	// error.
	pt.print();		// ok.. 단, print()가 상수 멤버함수 라면.. 
}


