#include <iostream> 
#include <fstream>  
#include <sstream>  
#include <string>
#include <iomanip>

int main()
{

	int    n = 3;
	double d = 3.454566756;

	// n, d 의 값을 서식화된 문자열로 만들고 싶다.
	// ex) "n = 3, d = 3.4" 의 문자열로
	// 
	// 1. C 스타일.
	char s[32];
//	sprintf(s, "n = %d, d = %lf", n, d);		// n, d의 값에 따라 버퍼 오버 플로우 가능성있음.
	snprintf(s, 32, "n = %d, d = %lf", n, d);	// 버퍼가 작으면 문자열 잘림.

	// 2. C++ 스타일 
	std::ostringstream sout;
	
	sout << "n = " << n << ", ";
//	sout << "d = " << d;
	sout << "d = " << std::setprecision(10) << d; // 소수점이하 자리수 지정

	std::string s1 = sout.str();

	std::cout << s1 << std::endl;
}
