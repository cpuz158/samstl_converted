#include <iostream>
#include <memory>
#include <vector>

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

int main()
{
	std::vector<Point> v1;
	v1.emplace(1, 1);
	v1.emplace(2, 2);
	// v1 파괴시, 모든 객체 자동 파괴.
	//-------------------------

	std::vector<Point*> v2;
	v2.push_back(new Point(1, 1));
	v2.push_back(new Point(2, 2));

	// v2가 파괴되기전에 사용자가 new 한것은 꼭 delete 해야 합니다.
	for (auto p : v2)
		delete p;

	//-------------------------
	std::vector< std::shared_ptr<Point> > v3;

//	v3.push_back( new Point(1, 2) ); // error
	v3.push_back( std::shared_ptr<Point>(new Point(1, 2)) ); // ok

	v3.push_back( std::make_shared<Point>(1, 1) ); // 최선의 코드
									// 결국 new Point(1,1) 로 만든객체를 전달하는것

}
// 스마트 포인터 개념 : 1990년대 말에 등장
// boost 라이브러리 에서 2000년 경에 shared_ptr 지원
// C++11 만들때 C++ 표준으로 "shared_ptr" 채택.

/*
void foo()
{
	int* p = new int;
	if (실패)
	{
		delete p; // 계속 해야 하므로 불편 합니다.
		return;
	}

	delete p;
}
*/