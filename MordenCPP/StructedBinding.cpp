#include"StructuredBind.h"

#include<utility>
#include<vector>
#include<iostream>

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

void StructuredBind_Test() {
	beforeBind();
	afterBind();
}