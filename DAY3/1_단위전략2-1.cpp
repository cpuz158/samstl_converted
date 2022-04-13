#include <vector>
#include <iostream>

// STL 컨테이너에 전달할 메모리 할당 정책을 담은 할당기 만들기

// 메모리 할당, 해지 정책을 담은 allocate/deallocate 함수를 제공하면 됩니다.
template<typename T> struct debug_alloc
{
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
//	std::vector<int> v(5); // 메모리 할당이 필요할때 마다 
						   // std::allocator 를 사용해서 할당

	std::vector<int, debug_alloc<int> > v(5);

	v.resize(10);
}


