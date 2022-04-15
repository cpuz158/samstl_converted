// g++ 소스이름.cpp -S 하면 어셈코드 볼수 있습니다.
// cl  소스이름.cpp /FAs 해도 소스.asm 파일 생성됩니다.
// cl  소스이름.cpp /FAs /O2 하면 최적화 됩니다.

// reordering : 컴파일러가 최적화 하면서
//				코드의 순서를 변경해 놓는 현상
#include <atomic>

int a = 0;
int b = 0;

// foo, goo 는 다른 스레드가 실행합니다.
void foo()
{
	a = b + 1;

//	__asm { mfence }  // <== 메모리 펜스 설치
					  // 위 코드는 아래 펜스를 넘을수 없다.

	std::atomic_thread_fence(std::memory_order_seq_cst);

	b = 1;
}

void goo()
{
	if (b == 1)
	{
		// a는 반드시 1일까요 ?
	}
}

int main()
{
}