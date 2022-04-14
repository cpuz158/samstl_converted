#include <iostream>

// 스마트포인터는 반드시 "얕은 복사" 문제를 해결해야 합니다.
// 아래 코드는 "얕은복사" 문제가 있는 코드입니다.
template<typename T>
class Ptr
{
	T* obj;
public:
	Ptr(T* p = 0) : obj(p) {}
	~Ptr() { delete obj; }

	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

int main()
{
	Ptr<int> p1 = new int;
	Ptr<int> p2 = p1; // 이때의 문제점을 생각해 보세요.
					  // 복사 생성자 호출(사용자가만들지 않으면 컴파일러제공버전사용)
}



