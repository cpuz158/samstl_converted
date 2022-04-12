// 반복자정리

// 1. 반복자 개념, 컨테이너에서 꺼내는 법, "s.end()" 는 past the end

// 2. 반복자의 형태 : "객체형 반복자", "raw 포인터"
//					위의 차이점 때문에 "T::value_type" 는 좋지 않다.
//					"std::iterator_traits<T>::value_type" 가 좋다

// 3. 반복자의 5가지 분류(iterator_category)
//    입력, 출력, 전진형, 양방향, 임의접근
//    알고리즘은 자신이 요구하는 반복자의 category 가 있다.
//	  std::sort(임의접근 first, 임의접근 last)

// 4. 삽입반복자 3가지 - 전방, 후방, 임의 삽입
//    std::copy(s1.begin(), s1.end(), s2.begin()); 
//    std::copy(s1.begin(), s1.end(), std::back_inserter(s2)); 

// 5. stream 반복자 - 표준 입출력, 파일 입출력..
//    show.h 의 show() 함수 참고..

// 6. reverse iterator 개념
//    reverse iterator 덕분에 모든 알고리즘 함수는 역방향으로도 동작한다
//    => 뒤에서 부터 선형 검색
//    
// 7. 컨테이너에서 반복자를 꺼내는 4가지 방법
//    c.begin();
//    c.rbegin();
//    c.cbegin();
//    c.crbegin();
