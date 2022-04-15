#include <iostream>
#include <vector>
#include <list>

/*
void print_first_element(std::vector<int>& v)
{
	int n = v.front();
	std::cout << n << std::endl;
}
*/

/*
template<typename T>
void print_first_element(std::vector<T>& v)
{
	T n = v.front();

	std::cout << n << std::endl;
}
*/

template<typename T>
void print_first_element(T& v)
{
	// ?채워 보세요. auto 말고.
	// T : list<double>
	// T::value_type ==> list<double>::value_type => double

	typename T::value_type n = v.front();

	// 그런데, C++11 이후에는 그냥 "auto" 사용하면 됩니다.
	auto n2 = v.front();

	std::cout << n << std::endl;
}




int main()
{
//	std::vector<int>    v = { 1,2,3,4,5,6,7,8,9,10 };
//	std::vector<double> v = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<double>   v = { 1,2,3,4,5,6,7,8,9,10 };

	print_first_element(v);
}

// template 기반 컨테이너를 만들때, 컨테이너가 저장하는 타입을 외부에서 알고 싶을때가 
// 있습니다. 위 처럼 print_first_element 함수에서..

/*
// 그래서 규칙이 있습니다.
template<typename T> class list
{
public:
	using value_type = T;	// STL 의 모든 컨테이너에는 이 코드가 있습니다.
							// typedef T value_type;
						 
	// ....
};

list<int> s = { 1,2,3 };
list<int>::value_type n = s.front();
*/