// 3_함수객체4 -  137 page 제일 윗부분내용

       int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	// Add1은 인라인 이 아니므로 "호출"
	// 1. 인자1, 2 를 약속된 장소에 넣어 놓고(32bit는 stack, 64bit는 register)
	// 2. Add1 함수로 이동
	// push 2
	// push 1
	// call Add1
	int n1 = Add1(1, 2); 

	// Add2는 인라인 함수 이므로 "Add2"를 컴파일한후.. "Add2의 기계어 코드"
	// 를 아래 코드 왼쪽에 치환
	int n2 = Add2(1, 2);  // mov eax, 2
						  // add eax, 1
						  // mov n2, eax

	int(*f)(int, int) = &Add2;

//	if (사용자입력 == 1) f = &Add1;

	// f는 실행시 변경 가능하므로("변수" 이므로) 
	// 컴파일 할때는 f가 어느 함수를 가리키는지 알수 없습니다.
	// 그래서 아래 코드는 항상 호출입니다.
	f(1, 2); // "호출"
}
// 핵심 1. 인라인 치환은 "컴파일" 할때 수행되는 문법이다.
// 핵심 2. 인라인 함수라도, 함수 포인터에 담아서 호출하면 인라인 치환될수없다

