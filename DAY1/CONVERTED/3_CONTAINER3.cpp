#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {}
};

template<typename T> class slist_iterator
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = nullptr) : current(p) {}

	slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}
	T& operator*() { return current->data; }

	bool operator==(const slist_iterator& it) const { return current == it.current; }
	bool operator!=(const slist_iterator& it) const { return current != it.current; }
};




template<typename T> class slist
{
	Node<T>* head = nullptr;
public:
	void push_front(const T& a)
	{
		head = new Node<T>(a, head);
	}

	// list 같은 컨테이너를 만드는 사람은 반드시 자신의 반복자 클래스 이름을
	// 약속된 형태 "iterator" 라는 이름으로 외부에 알리기로 약속합니다

	using iterator = slist_iterator<T>; 

	// typedef slist_iterator<T> iterator 와 같은 의미 입니다

	
	
	iterator begin() { return iterator(head); }
	iterator end()   { return iterator(nullptr); }
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

	std::cout << *p << std::endl; 

	++p; 

	std::cout << *p << std::endl; 
}