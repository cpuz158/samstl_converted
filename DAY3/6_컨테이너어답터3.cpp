#include <list>
#include <vector>
#include <deque>
#include <stack>
#include <queue> // queue, priority_queue
#include "show.h"

// STL 에서 "container adapter" 는 3개 입니다.
// 1. stack
// 2. queue
// 3. priority_queue

int main()
{
	// 다음중 에러를 모두 골라 보세요
	// stack : sequence 의 한쪽 방향만 사용합니다.
	// queue : sequence 의 양쪽 방향을 사용합니다.
	std::stack<int, std::list<int>>   s1;
	std::stack<int, std::vector<int>> s2;
	std::stack<int, std::deque<int>>  s3;

	std::queue<int, std::list<int>>   q1;
	std::queue<int, std::vector<int>> q2; // error. 
										  // vector 는 앞쪽 막힘.
										  // 여기서 에러가 아니라	
										  // 사용할때(멤버함수호출) 에러 발생
	std::queue<int, std::deque<int>>  q3;

	q2.push(10); // 에러 아님. vector 의 뒤쪽(push_back)으로 넣기
	q2.front();  // 에러 아님. 제거가 아니므로
	q2.pop();    // 제거 해야 하는데 vector 는 pop_front() 없음


}



