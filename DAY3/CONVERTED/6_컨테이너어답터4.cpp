#include <stack>
#include <queue> // queue, priority_queue
#include <iostream>
#include "show.h"

int main()
{
	// 우선순위큐 : 요소를 꺼낼때 우선순위가 가장 높은
	//			요소가 나오게 된다.
	
	// priority_queue<저장타입, 내부컨테이너, 우선순위를계산할때 사용할함수객체타입>"

//	std::priority_queue<int> pq;

	std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
	
	
	pq.push(10);
	pq.push(-10);
	pq.push(-20);
	pq.push(20);
	pq.push(15);

	std::cout << pq.top() << std::endl; 
	pq.pop();
	std::cout << pq.top() << std::endl; 

}



