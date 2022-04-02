
#include <iostream>
#include <span>
#include <algorithm>

using std::span;
//����һ�������ȵ�����
void Span_worker(std::span<int> data)
{
	for_each(begin(data), end(data), [](int v)
			 { std::cout << v << " "; });
	std::cout << std::endl;
}

void Span_Test()
{
	std::cout << "||For: span learning" << std::endl;
	int data[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	Span_worker(data);
}
