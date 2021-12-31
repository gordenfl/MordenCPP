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
	//std::vector<std::pair<int, float>> data{ {1,1.2}, {3,3.14}, {2, 2.2} };
	std::pair<int, float> data{1, 3.2};
	//const auto& [x, y] = data;
	std::cout << std::endl;
}

void StructuredBind_Test() {
	beforeBind();
	afterBind();
}