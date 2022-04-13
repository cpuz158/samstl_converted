#include <set> // Red Black Tree
#include <functional>
#include "show.h"

// STL 은 크기 비교도 모두 "단위전략" 으로 합니다.
// 메모리 할당기 조건 : allocate, deallocate 필요
// 크기 비교(Pred)조건 : operator()(T a, T b) 가 있어야 한다.
//						a,b 의 크기 비교후 bool 반환
template<typename T, typename Pred = std::less<T>, typename Alloc = std::allocator<T>>
class set
{
	Alloc ax; // 메모리 할당이 필요할때 사용
	Pred pred; // 요소의 크기 비교를 위한 객체.
public:
	void insert(const T& newElem)
	{
//		if (rootElem < newElem) // 이렇게 만들면 크기 비교정책을 교체할수 없습니다.
		if ( pred(newElem, rootElem) )
			add right child;

		else if (pred(rootElem, newElem))
			add left child;
		else
			fail; // set 은 요소의 중복을 허용하지 않습니다
				  // 이미 요소가 있다는것.
	}
};



int main()
{
	std::set<int> s; // Red Black Tree 입니다.

	s.insert(15);
	s.insert(25);
	s.insert(5);
	s.insert(17);
	s.insert(10);

	show(s);
}