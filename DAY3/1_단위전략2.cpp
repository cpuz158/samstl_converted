#include <vector>

// resize 의 원리를 생각해 봅시다.
// 메모리 할당기(allocator) : 메모리 할당 정책을 담은 클래스
//						   
template<typename T, typename Alloc = std::allocator<T> > 
class vector
{
	Alloc ax; // 2번째 인자로 전달 받은 할당기의 객체를 멤버로 포함
			  // 메모리 할당이 필요할때 마다 이 할당기 사용
public:
	void resize(int sz)
	{
		// 메모리 할당이 필요한 경우 어떻게 할까요 ?
		// new ? malloc ? memory pool
		T* buff = ax.allocate(sz); // T 타입 sz 개 할당

		ax.deallocate(buff, sz); // 메모리 해지할때도 할당기에 의존.
	}
};

int main()
{
	std::vector<int> v(5);

	v.resize(10);
}


