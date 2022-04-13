// Policy Base Design ( 단위 전략 디자인 )

// 클래스가 사용하는 "어떤 정책" 을 템플릿 인자를 통해서 전달하는 것.

// 템플릿 인자로 전달되는 정책 클래스는 지켜야 하는 규칙을 가지게 됩니다.
// => 아래 코드에서는 "lock()/unlock()" 함수가 있어야 합니다.
// => 이런 규칙을 모아 놓은 것을 "named requirement" 라고 합니다.

// STL 은 "단위전략 디자인"을 아주 널리 사용합니다.

// 단, STL 컨테이너는 멀티스레드 동기화는 되지 않습니다.
// => 아래 처럼 되어 있지는 않습니다.



// 아래 클래스 에서 동기화 여부는 결국
// list 사용자가 템플릿 2번째 인자로 전달하는 타입에 따라 달라집니다.
template<typename T, typename ThreadModel = noLock> class List
{	
	ThreadModel tm;
public:
	void push_front(const T& a)
	{
		tm.lock();
		//....
		tm.unlock();
	}
};
//--------------------------------
// 동기화 정책을 담은 정책 클래스를 제공합니다.
class mutexLock
{
	// pthread_mutex_t handle;
public:
	inline void lock()   { } // pthread_acquire_mutex()
	inline void unlock() { } // pthread_release_mutex()
};
class noLock
{
public:
	inline void lock() { } 
	inline void unlock() { } 
};
//---------------------------------------
// 이제 List 사용자는 template  인자로 "동기화 정책"을 전달 합니다
//List<int, noLock> st;	// 전역변수는 멀티스레드 환경에서 안전하지 않습니다.
//List<int, mutexLock> st;
List<int> st;

int main()
{
	st.push_front(10);

}