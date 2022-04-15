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
	using iterator = slist_iterator<T>;
	using value_type = T;


	void push_front(const T& a)
	{
		head = new Node<T>(a, head);
	}
	
	iterator begin() { return iterator(head); }
	iterator end() { return iterator(nullptr); }
};




template<typename InputIter, typename T>
InputIter find(InputIter first, InputIter last, T value)
{
	while (first != last && *first != value)
		++first;

	return first;
}

int main()
{
	slist<int> s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);

	slist<int>::iterator p = find(s.begin(), s.end(), 30);

	if (p == s.end())
	{
		std::cout << "검색 실패" << std::endl;
	}
	else
	{
		std::cout << "검색 성공 : " << *p << std::endl;
	}

}
// 40 page 내용 설명
// STL : Standard Template Library
// STL 의 3대 요소 : Container, Iterator, Algorithm(find 같은 일반함수템플릿)

// 자료구조와 알고리즘이 분리된 형태의 라이브러리
// 알고리즘(find) 제작자는 자신이 어떤 자료구조에서 선형검색하는지 알필요 없이 제작

// 1일차 : Iterator(5시간이상
// 2일차 : 알고리즘(4~5), Container(8시간)
// 3일차 : Container