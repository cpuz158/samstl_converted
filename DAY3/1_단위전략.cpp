
// 아래 클래스 에서 동기화 여부는 결국
// list 사용자가 템플릿 2번째 인자로 전달하는 타입에 따라 달라집니다.
template<typename T, typename ThreadModel > class List
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
List<int, noLock> st;	// 전역변수는 멀티스레드 환경에서 안전하지 않습니다.

int main()
{
	st.push_front(10);

}