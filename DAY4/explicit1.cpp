// explicit1
#include <iostream>

class Bike
{
	int gear;
public:
	Bike(int n) : gear(n) {}
};

void fn(Bike b) {}

int main()
{
	// 인자가 한개인 생성자가 있으면 아래처럼 4가지 형태로 객체 생성이 가능합니다.
	Bike b1(10);
	Bike b2 = 10;
	Bike b3{ 10 };
	Bike b4 = { 10 };
}