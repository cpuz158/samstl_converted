// 6_optional
#include <iostream>
#include <optional>

int main()
{

	int n1 = 0; // n1 은 정수값을 가집니다.

//	std::optional<int> n2 = 10; // n2 는 정수값 + 값없음(null) 상태를 가질수 있습니다.
	std::optional<int> n2 = std::nullopt; 
	
	if (n2)
	{
		std::cout << "값 있음 : " << *n2 << std::endl;
	}
	else
		std::cout << "값 없음 " << std::endl;

}
