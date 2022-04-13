#include <iostream> 
#include <fstream>  
#include <sstream>  
#include <string>
#include <iomanip>

//				출력						입력
// 표준스트림		std::ostream cout		std::istream cin
// 파일스트림		std::ofstream			std::ifstream
// 메모리(문자열)	std::ostringstream		std::istringstream

int main()
{
	std::istringstream iss("to be or not to be");

	std::string s;
//	std::cin >> s; // 표준 입력(사용자)로 부터 한 단어 읽기

	while(iss >> s)
		std::cout << s << std::endl;
}
