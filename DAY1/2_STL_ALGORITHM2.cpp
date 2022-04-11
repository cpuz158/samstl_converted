#include <iostream>

// Step 2. 검색 구간의 일반화
// 전체 문자열 뿐 아니라 "부분 문자열도 검색" 가능 - 활용도가 넓어짐..
// 활용도를 점점 넓혀가는 작업 - 일반화! 한다도 이야기..

// [first, last) 사이의 문자열에서 "선형검색 수행"
// "반개행(half-open) 구간" 이라고 합니다.

char* xstrchr(char* first, char* last, int c)
{
	while (first != last && *first != c)
		++first;

	return first == last ? nullptr : first;
}


int main()
{
	char s[] = "abcdefgh";

	char* p = xstrchr(s, s + 4,  'c');

	if (p == nullptr)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}