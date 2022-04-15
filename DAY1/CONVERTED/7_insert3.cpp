#include <iostream>
#include <list>
#include <iterator>

// 삽입반복자종류

int main(int argc, char** argv)
{
	int x[5]    = { 1, 2, 3, 4, 5 };
	std::list<int> s = { 0, 0, 0, 0, 0 };


	// 삽입반복자는 3개가 있습니다.
	// 1. 후방 삽입 반복자
//	std::copy(x, x + 5, std::back_inserter(s)); // std::back_insert_iterator 생성
												// 0, 0, 0, 0, 0, 1, 2, 3, 4, 5

	// 2. 전방 삽입 반복자
//	std::copy(x, x + 5, std::front_inserter(s)); // std::front_insert_iterator 생성
												// 5,4,3,2,1,0,0,0,0,0

	// 3. 임의 삽입 반복자
	// std::inserter( 컨테이너, 삽입할위치를나타내는반복자p) : p앞에 삽입
//	std::copy(x, x + 5, std::inserter(s, ++(s.begin()) )); // std::insert_iterator 생성
												// 0,1,2,3,4,5,0,0,0,0

	// 임의 삽입으로 컨테이너 앞에 삽입 - 순서가 뒤집어 지지 않고 삽입됩니다.
	std::copy(x, x + 5, std::inserter(s, s.begin()) );
											// 1,2,3,4,5,0,0,0,0,0

	for (auto& n : s)
		std::cout << n << ", ";
}
