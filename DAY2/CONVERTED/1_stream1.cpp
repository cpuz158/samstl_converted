// 1. github.com/codenuri/samstl  에서 DAY2_사전소스.zip 받으세요
// 2. codexpert.org 에서 출석해주세요

// VC 사용하시는 분은
// SDK 버전
// 플랫폼 도구집합 버전 맞춰 주세요.














#include <iostream>
#include <iterator>
#include <list>
#include <algorithm> // copy 알고리즘.. 

int main()
{
	int n = 10;

	std::cout << n << std::endl;

	// 스트림 반복자 : 입출력에 사용되는 반복자.
	std::ostream_iterator<int> p(std::cout, " ");

	// 이제 p 를 사용하면 std::cout 이 사용하는 출력 버퍼에 출력됩니다.
	*p = 10; // std::cout << *p << " " 의 의미
	++p;     // 없어도 됩니다. ++ 자체는 하는일은 없습니다.
	*p = 20;

	std::list<int> s = { 1,2,3 };

	// list 의 모든 내용을 copy 알고리즘과 스트림 반복자로 출력하기
	std::copy(s.begin(), s.end(), p);
}