#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	int x[5] = { 1, 2, 3, 4, 5 };
	int y[5] = { 0, 0, 0, 0, 0 };
	
	std::list<int> s2 = { 0,0,0,0,0 };

	// x �� ��� ��Ҹ� y�� �����ϰ� �ʹ�.
	// 1. for �� ���
//	for (int i = 0; i < 5; i++)
//		y[i] = x[i];

	// 2. range-for
//	int i = 0;
//	for (auto e : x)
//		y[i++] = e; // �ε�.. i�� �ʿ� �մϴ�


	// 3. copy �˰������� ����ص� �˴ϴ�. - �������� ���� ����� ����
	std::copy(x, x + 5,  // [first, last) ����.. ������ ����
			  y);

	for (auto e : y)
		std::cout << e << ", ";

//	std::copy(s2.begin(), s2.end(), y); // �����̳ʹ���.
	std::copy(s2.rbegin(), s2.rend(), y); // �������� ����.. 
										  // ������ ����..

	// �����̳ʰ�, �迭�̰�.. �ᱹ �ݺ��ڷ� �۾��ϹǷ�.. �����ϰ� ���
}
// ����!!
// �ݺ��ڶ� : "�ݺ��� ó�� �����ϴ� ��� ���� �ݺ����̴�."
//          ++�� �̵������ϰ�, *�� ��� ������ �����ϸ� �ݺ��̴�.
// 1. slist_iterator ó�� Ŭ������ ����͵� �ݺ��� �̰�..
// 2. int* p ó�� raw pointer�� �ݺ��� �̴�.