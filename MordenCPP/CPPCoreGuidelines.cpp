#include"CPPCoreGuidelines.h"

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<span>
#include<chrono>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::span;

Month Date::month() const {
	return _month;
}

//for_each �� algorithm ͷ�ļ�� ������Ӵ�һ��lambda
void ExampleForEach() {
	std::vector<int> data{ 1,2,3,4,5,6,7,8,9 };
	for_each(begin(data), end(data), [](int v) {
		std::cout << v << " ";
		});
	std::cout << std::endl;
}

void Find(vector<string>& data, string & target) {
	auto p = find(begin(data), end(data), target); //return is an iterator
	if (p!=data.end()) {
		std::cout << "Find the target:" << *p << std::endl;
	}
	else {
		std::cout << "Don't find target:" << target << std::endl;
	}
}
template<class rep, class period>
void blinked(std::chrono::duration<rep, period> delta) {
	auto milliseconds_to_blink = duration_cast<milliseconds>(delta);
	std::cout<< "second:"<< milliseconds_to_blink <<std::endl;
}
void ArgsWithType() {
	blinked(12s);
}

void Cpp_Core_Test() {
	cout << "||For: for_each learning" << endl;
	ExampleForEach();

	cout << "||For: find learning" << endl;
	auto data = std::vector<std::string>{ "AAA", "BBB", "CCC", "DDD", "target"};
	auto target = string("BBB");
	Find(data, target);

	

}