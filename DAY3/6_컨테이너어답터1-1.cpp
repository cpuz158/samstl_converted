#include <iostream>

// list 가 이미 있습니다
#include <list>
#include <vector>
#include <deque>

// 그런데, 스택이 필요합니다.
// 1. 새로 만들자.
// 2. list를 스택처럼 보이게 하자.

// "Adapter Pattern" : 기본 클래스의 인터페이스(함수이름)을
//					변경해서 새로운 클래스를 만드는 디자인 패턴.

template<typename T, typename Cont = std::deque<T> > class stack
{
	Cont c;
public:
	inline void push(const T& a) { c.push_back(a); }
	inline void pop() { c.pop_back(); }  
	inline T& top()   { return c.back(); }
};

#include <stack> // 이 안에 위 코드가 있습니다.
				 // 흔히 "stack adapter" 라는 용어로 부릅니다.

int main()
{
	stack<int> s; // deque에 보관
	stack<int, std::list<int> > s1;   // list 를 스택처럼 보이게 해달라는것
									  // 그래서 "stack adapter" 라고 합니다.
	stack<int, std::vector<int> > s2;

	s.push(10);
	s.push(20);

	std::cout << s.top() << std::endl;

}