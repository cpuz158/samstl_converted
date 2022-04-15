#include <iostream>

// 싱글 링크드 리스트 입니다
template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {}
};

template<typename T> class slist
{
	Node<T>* head = 0;
public:
	// 싱글리스트는 아래 처럼 생성자만 잘 활용하면
	// 간단하게 만들수 있습니다.
	void push_front(const T& a)
	{
		head = new Node<T>(a, head);
	}
	// 나중에 pop_front(), 소멸자 같은 코드 만드세요
	// delete 할수 있게 해보세요..
};

int main()
{
	// 31 page 그림 참고 하세요
	slist<int> s;
	
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);
}