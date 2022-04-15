#include <iostream>
#include <list>

int main()
{
	std::list<int> s1 = { 1,2,3 };

	auto p1 = std::begin(s1); // 1번째 요소를 가리키는 반복자
	auto p2 = std::end(s1);	  // 마지막 다음 요소를 가리키는 반복자
							  // "past the end"
	*p1 = 10; // ok
//	*p2 = 20; // runtime error. std::end()로 얻는 반복자는 * 하지 마세요


	// end()로 얻는 반복자는 비교의 용도로만 사용하세요
	// [p1, p2)
	while (p1 != p2)
	{
		++p1;
	}

	// end()는 past the end 이므로 begin() == end() 라는 의미는 empty 의 의미.
	std::list<int> s3;
	if (s3.empty()) {}

	if (std::begin(s3) == std::end(s3)) {}	
}