// 상수 멤버 함수는 선택이 아닌 필수 문법입니다.
// 멤버 함수를 만들때, 객체의 상태를 변경하지 않은 모든 멤버함수(getter)는
// 반드시 "상수 멤버 함수"로 해야 합니다.

class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x{ x }, y{ y }, w{ w }, h{ h } {}

	int getArea() const { return w * h; }
};

//void foo(Rect r)   // 사용자 정의 타입을 인자로 받을때는 call by value 는 좋지않다
void foo( const  Rect& r)
{
	int n = r.getArea(); 
}
int main()
{
	Rect r(1,2,3,4);	 // 상수객체 아님. 
	int n = r.getArea(); // ok. 
	foo(r);
}