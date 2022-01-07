#include"CPPCoreGuidelines.h"

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<span>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::span;

Month Date::month() const {
	return _month;
}

//for_each 在 algorithm 头文件里， 这个例子带一个lambda
void ExampleForEach() {
	std::vector<int> data{ 1,2,3,4,5,6,7,8,9 };
	for_each(begin(data), end(data), [](int v) {
		std::cout << v << " ";
		});
	std::cout << std::endl;
}

void Find(vector<string>& data, string& target) {
	auto p = find(begin(data), end(data), target); //return is an iterator
	if (p != data.end()) {
		std::cout << "Find the target:" << *p << std::endl;
	}
	else {
		std::cout << "Don't find target:" << target << std::endl;
	}
}


void Cpp_Core_Test() {
	cout << "||For: for_each learning" << endl;
	ExampleForEach();

	cout << "||For: find learning" << endl;
	auto data = vector<string>{ "AAA", "BBB", "CCC", "DDD", "target" };
	auto target = string("BBB");
	Find(data, target);


}