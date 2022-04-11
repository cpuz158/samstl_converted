// C++ STL Programming 과정입니다.
// 강석민 강사 ( smkang @ codenuri.co.kr )

// 출석 : codexpert.org "손들기"

// github.com/codenuri/samstl  에 가시면

// "DAY1_사전소스.zip" 있습니다. 받아 두세요

// 실습환경 : 표준 C++ 언어를 컴파일할수 있는 어떠한 컴파일러도 사용가능.
//          강사 : Visual Studio 2022버전( 2017 이상이면 가능 )

// 평가 : 마지막날 마지막 시간에 "필기(오픈북)"으로 진행

// isocpp.org 에 접속해 보세요.

// 일정
// 1 ~ 3일차 : 자료구조와 알고리즘 위주의 라이브러리 소개
// 4 ~ 5일차 : 스마트포인터, 파일 시스템, function, 스레드등의 유틸리티
// 5일차 오후 : C++20 의 range library 소개

// 수업에서 다루는 모든 소스는 

// github.com/codenuri/samstl  에 즉시 올리겠습니다.

//-------------------------
// codexpert.org




// 1. VS 로 실습하시는 분들은 "버전을 맞춰야 합니다."

// "프로젝트 메뉴" => "DAY1" 속성 메뉴 선택후

// 1. windows sdk 버전 - (최신버전)
// 2. 플랫폼도구 집합 버전
// 3. C++ 언어 버전 - 디폴트(C++14로 하시면 됩니다. 그 이상도 문제없음)


// 2. 그리고, "x86" - 32bit, "Debug" 환경에서 진행하겠습니다.

// 3. 프로젝트에서 소스 파일을 "빌드 참여/참여안함" 변경하는법
// 파일에서 오른쪽 버튼 누른후에 "속성" 선택하시면 됩니다.
// 











// 1_STL_PREVIEW1 - 6page
#include <iostream>
#include <string>

int main()
{
	char s1[] = "Hello";
	char s2[] = "Hello";

	if (s1 == s2) {} // 항상 False
					 // 의도 대로 하려면 "strcmp(s1, s2) == 0 "
	
//	s2 = s1; // error
			 // 의도대로 하려면 strcpy(s2, s1)
			 // strcpy_s(s2, strlen(s2), s1);

	std::string s3 = "hello"; // C++ 표준의 문자열 클래스
	std::string s4 = s3; 
	s4 = s3;
	s4 = s3 + s3; // s4 = s3 * 2; error. * 안됩니다. 

	if (s3 == s4) {}


}