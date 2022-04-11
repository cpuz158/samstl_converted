#include <iostream>
#include <list>

// raw array 뿐 아니라 STL container 도 가능한 sum 만들기
// "T"가 반복자 일때 "T::value_type" 은 반복자가 가리키는 타입 입니다.

template<typename T> 
typename T::value_type sum(T first, T last)
{
	typename T::value_type s = 0;

	while (first != last)
	{
		s = s + *first;
		++first;
	}
	return s;
}

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	int n = sum(std::begin(s), std::end(s));

	std::cout << n << std::endl; // 55
}
