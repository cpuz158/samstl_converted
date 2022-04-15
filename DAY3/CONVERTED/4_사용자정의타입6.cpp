//5_사용자정의타입5
#include <vector>
#include <iostream>

class Shape
{
public:
	// "모든 기반 클래스의 소멸자는 반드시 가상함수 이어야 한다." 라는 규칙이 있으므로
	// 결국, 상속을 사용하는 코드는 대부분 가상함수가 한개 이상은 있습니다.
	virtual ~Shape() {}
};




class Point : public Shape
{
};
class Rect : public Shape
{
public:
	void draw() const {}
};

int main()
{
	// 기반 클래스 포인터를 보관하면 모든 파생 클래스객체를 담을수 있습니다
	std::vector<Shape*> v;
	v.push_back(new Point);
	v.push_back(new Rect);
	v.push_back(new Rect);
//	v.push_back(new int); // error

	// 그런데, v는 Shape* 로 보관하므로 Rect의 소유 멤버 접근은 안됩니다.
//	v[2]->draw(); // error.

	// 고유 멤버 접근이 필요하면 캐스팅해야 합니다
	// 방법 1. 타입을 명확히 확실할수 있다면 static_cast 하세요
//	Rect* p1 = static_cast<Rect*>(v[2]);
//	p1->draw();

	// 방법 2. 확실할수 없다면, dynamic_cast 하세요
//	Rect* p2 = dynamic_cast<Rect*>(v[2]);
	Rect* p2 = dynamic_cast<Rect*>(v[0]);

	std::cout << p2 << std::endl;
}