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
		current = current->next;
		return *this;
	}
	T& operator*() { return current->data ; }

	bool operator==(const slist_iterator& it) const { return current == it.current; }
	bool operator!=(const slist_iterator& it) const { return current != it.current; }
};

//slist_iterator p(400번지);
//++p; // p.operator++()
//*p;  // p.operator*()





template<typename T> class slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a)
	{
		head = new Node<T>(a, head);
	}

	// find 로 보내려면 처음을 가리키는 반복자와 마지막 다음을 가리키는 반복자가 필요합니다.
	// 모든 컨테이너(list같은 클래스)에 아래 2개의 함수를 만들기로 약속합니다.
	slist_iterator<T> begin() { return slist_iterator<T>(head); }
	slist_iterator<T> end()   { return slist_iterator<T>(0); }
};

int main()
{
	slist<int> s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);

	slist_iterator<int> p = s.begin();

	// 이제 p는 포인터와 유사하게 동작합니다.
	// 포인터 처럼 생각하고 사용하세요.
	std::cout << *p << std::endl;
	++p;
	std::cout << *p << std::endl;
}