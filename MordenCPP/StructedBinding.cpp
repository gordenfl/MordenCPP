#include"StructuredBind.h"

#include<utility>
#include<vector>
#include<iostream>
#include<string>
#include<map>

void beforeBind() {
	std::vector<std::pair<int, float>> data{ {1,1.2}, {3,3.14}, {2, 2.2} };
	for (auto p : data) {
		int f = p.first;
		float s = p.second;
		std::cout << f << ":" << s << "| ";
	}
	std::cout << std::endl;
}

void afterBind() {
	std::vector<std::pair<int, float>> data{ {1,1.2}, {3,3.14}, {2, 2.2} };

	for (auto v : data) {
		const auto& [a, b] = v;
		std::cout << a << "->" << b << std::endl;
	}
}

void afterBindRangeVeter() {
	std::vector<std::pair<int, float>> data{ {1,1.2}, {3,3.14}, {2, 2.2} };

	for (auto& [i, v] : data) {
		//const auto& [a, b] = v;
		std::cout << i << "->" << v << std::endl;
	}
}

void afterBindRangeMap() {
	std::map<std::string, std::string> data{ {"hi", "HI"}, {"Hello", "HELLO"} };

	for (auto& [key, value] : data) {
		//const auto& [a, b] = v;
		std::cout << key << "->" << value << std::endl;
	}
}
void StructuredBind_Test() {
	beforeBind();
	afterBind();
	afterBindRangeVeter();
	afterBindRangeMap();
}