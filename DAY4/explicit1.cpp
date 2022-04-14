// explicit1
#include <iostream>

class Bike
{
	int gear;
public:
	// explicit  생성자 : 직접 초기화만 가능하고, 복사 초기화는 할수 없다.
	explicit Bike(int n) : gear(n) {}
};
// 함수 인자를 받는 것은 아래 주석 처럼 되어 있는 코드 입니다.
void fn(Bike b) {} // "Bike b = 10"  처럼 복사 초기화가 되는 것 입니다.
				   // "Bike b = Bike(10)"
int main()
{
	// 인자가 한개인 생성자가 있으면 아래처럼 4가지 형태로 객체 생성이 가능합니다.
	// C++98
	Bike b1(10);	// 직접(direct) 초기화
	Bike b2 = 10;	// 복사(copy) 초기화

	// C++11 
	Bike b3{ 10 };		// 직접(direct) 초기화
	Bike b4 = { 10 };	// 복사(copy) 초기화

	fn(10); // error
	fn( Bike(10) ); // ok. 이경우는 "Bike b = Bike(10)" 이므로
							// int 인자 한개의 생성자가 아닌
							// 복사 생성자를 호출하게 됩니다.
}