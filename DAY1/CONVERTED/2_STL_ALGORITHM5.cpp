#include <iostream>

// Step 5. 실패에 대한 반환값 변경

// 검색 실패시
// nullptr 대신 last 반환
// 1. find 구현자체도 조금 빨라진다. 아래 코드 참고
// 2. 활용도가 좋다. find 실패시 반환값은 다음 검색 구간의 시작이 된다.
// 3. 유연성도 좋다. 스마트 포인터 사용시 모든 스마트 포인터가 nullptr과 
//				  호환될 필요도 없어 진다.
template<typename T1, typename T2>
T1 find(T1 first, T1 last, T2 value)
{
	while (first != last && *first != value)
		++first;

	return first; //  == last ? nullptr : first;
}
int main()
{
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	double* p = find(x, x + 10, 5.0f); // ??

	if (p == x+10)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}