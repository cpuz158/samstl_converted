// 3개의 컨테이너 어답터가 있습니다.
#include <stack>
#include <queue> // queue, priority_queue
#include "show.h"

int main()
{
	std::stack<int> s1;
	s1.push(10);

	// 내부 컨테이너를 변경하는 방법
	std::stack<int, std::vector<int> > s2;

	// 질문 : stack s3를 만드세요
	// 1. 내부 컨테이너 vector로 하세요
	// 2. 단위전략3-1에 있는 "debug_alloc" 을 사용해 보세요.
	
	std::stack< ? > s3;

	s3.push(10);
	s3.push(20);

}