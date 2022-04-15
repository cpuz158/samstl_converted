#include <set> 
#include <functional>
#include "show.h"

// set 에 "비교정책(템플릿 2번째 인자)" 으로 전달하는 타입의 조건은
// "operator()" 함수가 있으면 됩니다. - 즉, "함수객체"를 만들어야 합니다.

template<typename T>
struct Greater
{
	// 함수 객체 만들때 "operator()" 를 꼭 상수 멤버 함수로 하세요.
	// const Greater g; 로 만들었어도
	// if ( g(10, 20) ) 할수 있어야 합니다 g.operator()(10,20) 호출가능하게
	inline bool operator()( const T& a, const T& b) const 
	{ 
		return a > b; 
	}
};

int main()
{
	Greater<int> g;
	const int n1 = 10, n2 = 20;
	g(n1, n2);




//	std::set<int, Greater<int> > s; 
	std::set<int, std::greater<int> > s;

	s.insert(15);
	s.insert(25);
	s.insert(5);
	s.insert(17);
	s.insert(10);

	show(s);
}