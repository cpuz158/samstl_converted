#include <iostream>

// 싱글 링크드 리스트 입니다
template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {}
};

// list 안에 있는 Node를 가리킬수 있는 
// 포인터 역활의 클래스(iterator)를 만들어 봅시다.
template<typename T> class slist_iterator
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr) : current(p) {}

	// 우리의 목표는 find로 보낼수 있어야 합니다.
	// ++, !=, ==, * 를 재정의 해서
	// "raw pointer" 처럼 동작할수 있게 해야 합니다.

	slist_iterator& operator++()
	{
		? ;
		return *this;
	}
	T& operator*() { return ? ; }

	bool operator==(const slist_iterator& it) const {} 
};

slist_iterator p(400번지);
++p; // p.operator++()
*p;  // p.operator*()













template<typename T> class slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a)
	{
		head = new Node<T>(a, head);
	}
};

int main()
{
	slist<int> s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);
}