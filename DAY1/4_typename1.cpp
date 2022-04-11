class Test
{
public:
	enum { value = 1 };
	typedef int DWORD;
};
int p = 0;

template<typename T> void foo(T a)
{
	// 아래 2줄에서 * 의 의미를 생각해 보세요(1. 곱하기, 2. 포인터 변수 선언)
	
	// "클래스이름::이름" 에서 "이름"의 의미는 "값" 또는 "타입" 입니다.
//	Test::value * p; // 곱하기 의미					=> 값
//	Test::DWORD * p; // 포인터 변수 p를 선언 한것.		=> 타입


	// 아래 2줄을 생각해 보세요
	// "T::이름" 처럼 표기하는 컴파일러는 "이름"을 무조건 "값"으로 해석합니다.
	T::value * p;  // ok
	T::DWORD * p;  // error
}


int main()
{
	Test t;
	foo(t);
}