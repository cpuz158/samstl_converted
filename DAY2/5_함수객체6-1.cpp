struct Less
{
	inline bool operator()(int a, int b) { return a < b; }
};
struct Greater
{
	inline bool operator()(int a, int b) { return a > b; }
};
//----------------------------------------------------
// 비교 정책을 교체할수 있는데, 
// 비교 정책 함수(객체)의 인라인 치환이 가능한 sort() 만드는 기술
// "템플릿 + 함수객체" 를 사용하는 기술로 "STL 설계원리"
template<typename T>
void Sort(int* x, int sz, T cmp )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if ( cmp(x[i], x[j]) == false)
				std::swap(x[i], x[j]);
		}
	}
}

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	Less    f1; f1(1, 2); Sort(x, 10, f1); // ok..
	Greater f2; f2(1, 2); Sort(x, 10, f2); // ?
}



