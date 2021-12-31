#include"InitializerList.h"

#include<vector>
#include<iostream>
#include<utility>
#include<map>
#include<string>
#include<assert.h>
#include<set>

template<typename T>
void Output(T & data) {
	for (auto v : data) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}

void OutputPairs(std::vector < std::pair<int, int>>& data) {
	for (auto v : data) {
		std::cout << "first:" << v.first << " second:" << v.second << "  |  ";
	}
	std::cout << std::endl;
}
void OutputMap(std::map<std::string, int> data) {
	for (auto d : data) {
		std::cout << d.first << ":" << d.second << "|";
	}
	std::cout << std::endl;
}

/// <summary>
/// Vector Init
/// </summary>
void OldVectorInit() {
	std::vector<int> data;
	data.push_back(1);
	data.push_back(2);
	data.push_back(3);

	Output(data);
}

void NewVectorInit() {
	std::vector<int> l = { 1,2,3,4,5 }; //may cause low efficient, suggest next line
	std::vector<int> v{ 1,2,4,5,6,7 }; //C++11
	/*
	initializer_list<int> l = { 1,2,3,4,5,6 };
	std::vector<int> v1(l);
	*/
	Output(v);


}

/// <summary>
/// vector pair initial
/// </summary>
/// 
/// 
/// 
void oldVectorOfPair() {
	std::vector<std::pair<int, int>> data;
	std::pair<int, int> v1(1, 2);
	data.push_back(v1);
	std::pair<int, int> v2(3, 4);
	data.push_back(v2);
	std::pair<int, int> v3(5, 6);
	data.push_back(v3);
	std::pair<int, int> v4(7, 8);
	data.push_back(v4);
	OutputPairs(data);

}
void newVectorOfPair() {
	std::vector<std::pair<int, int>> data = { {1,2}, {3,4}, {5,6}, {7,8} };
	OutputPairs(data);
}


/// <summary>
/// map 
/// </summary>
/// 
void oldMap() {
	std::map<std::string, int> name_age;
	name_age["gordon"] = 41;
	name_age["oneqiong"] = 39;
	name_age["bing"] = 11;
	name_age["key"] = 9;
	OutputMap(name_age);
}

void newMap() {
	std::map<std::string, int> name_age{ {"gordon", 41}, {"oneqiong", 39}, {"bing", 11}, {"ken", 9} };
	OutputMap(name_age);
}

void TestMap() {
	oldMap();
	newMap();
}

/// <summary>
/// test error
/// </summary>
void TestError() {
	std::pair<int, int> a(5, 1);
	std::pair<int, int> b{ 5,1 };
	assert(a == b);

	std::vector<int> vb(5, 3); //3, 3, 3, 3, 3
	std::vector<int> va{ 5, 1 }; //5, 1
	assert(va != vb);
}

/// <summary>
/// return value
/// </summary>
/// 
std::vector<int> oldfoo() {
	std::set<int> data = { 1,2,3,4,5,6 };
	return std::vector<int>(begin(data), end(data));
}
std::vector<int> newfoo() {
	std::set<int> data = { 1,2,3,4,5,6 };
	return { begin(data), end(data) };
}

void TestReturn() {
	std::vector<int> a = oldfoo();
	Output(a);

	std::vector<int> b = newfoo();
	Output(b);
}

void InitializerList_Test() {
	OldVectorInit();
	NewVectorInit();

	oldVectorOfPair();
	newVectorOfPair();

	TestMap();

	TestError();

	TestReturn();	
}