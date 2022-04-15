#include <vector>
#include <iostream>

// C++ 에서 struct 와 class 는 단, 한개의 차이점만 있습니다
// struct : 접근지정자 생략시 public
// class  : 접근지정자 생략시 private

// POD 라는 용어는 => "trivial" , "standard layout" 이라는 용어로 변경됩니다
// std::is_pod<> 도 사라졌습니다.
/*
class Point
{
public:
	int x, y;
};
*/

// STL 컨테이너에 전달할 메모리 할당 정책을 담은 할당기 만들기

// 메모리 할당, 해지 정책을 담은 allocate/deallocate 함수를 제공하면 됩니다.
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
//	std::vector<int> v(5); // 메모리 할당이 필요할때 마다 
						   // std::allocator 를 사용해서 할당

	std::vector<int, debug_alloc<int> > v(5);

	v.resize(10);
}


