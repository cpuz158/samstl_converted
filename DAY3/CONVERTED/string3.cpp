
#include <iostream>
#include <string>

template<typename T,   
	typename Traits = std::char_traits<T>, 
	typename Alloc = std::allocator<T> >   
class basic_string
{
	T* buff;
	Alloc ax;// ax.allocate
public:
	bool operator==(const basic_string& other)
	{
		// 문자열의 상등 조사도 단위 전략으로 교체 할수 있게 만들었습니다.
		// 그런데, 아래 코드를 잘보면 compare 는 static 멤버함수로 
		// 만들어야 합니다.
		return Traits::compare(buff, other.buff);
	}
};

int main()
{
	std::string s1 = "abcd";
	std::string s2 = "ABCD";

	bool b = (s1 == s2);

	std::cout << b << std::endl;
	

}