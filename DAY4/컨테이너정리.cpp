// 컨테이너정리

// sequence container 
// => vector, list, deque,     C++98
// => array, forward_list      C++11
// => string 을 이 분류에 넣기도 합니다.

// container adapter 3개 ( sequence 의 함수이름을 변경하는 도구)
// => stack, queue, priority_queue

// associative container
// => set, map					   : tree 기반
// => unordered_set, unordered_map : hash 기반

//-------------------------------------------
// graph 등이 아직 없습니다.
// 
// boost.org 에서 boost 라이브러리를 설치하면 더 많은 컨테이너를 사용가능
// boost 라이브러리에서 안전성과 필요성이 검증되면 
// 추후 C++ 표준에 추가되게 됩니다.

// set, map : 정렬이 필요 한데, 검색도 빨라야 한다. => IndexMap 예제
// unordered : 정렬 필요 없고, 검색이 제일 중요 한다.
/*
unordered_map<std::string, int> macro;

#define MAX 10  // #define 을 만나면 macro["MAX"] = 10

int main()
{
	int n = MAX;
}
*/
// 전처리기 만들어 보세요. => 정렬 필요 없고 검색이 제일 중요 하므로
//							hash 로 하면 됩니다.

