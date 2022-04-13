// 3개의 컨테이너 어답터가 있습니다.
#include <stack>
#include <queue> // queue, priority_queue
#include "show.h"

template<typename T> class debug_alloc
{
public:
	T* allocate(std::size_t sz)
	{
		T* ptr = static_cast<T*>(malloc(sizeof(T) * sz));

		printf("%d allocated at %p\n", sz, ptr);
		return ptr;
	}
	void deallocate(T* ptr, std::size_t sz)
	{
		free(ptr);
		printf("%d deallocated at %p\n", sz, ptr);
	}

	// 위 2개위에도 아래 3개가 있어야 합니다.
	using value_type = T;
	debug_alloc() {}
	template<typename U> debug_alloc(const U&) {} // 템플릿 생성자라는 함수
};

int main()
{
	std::stack<int> s1;
	s1.push(10);

	// 내부 컨테이너를 변경하는 방법
	std::stack<int, std::vector<int> > s2;

	// 질문 : stack s3를 만드세요
	// 1. 내부 컨테이너 vector로 하세요
	// 2. 단위전략2-1에 있는 "debug_alloc" 을 사용해 보세요.
	
	std::stack< ? > s3;

	s3.push(10);
	s3.push(20);

}