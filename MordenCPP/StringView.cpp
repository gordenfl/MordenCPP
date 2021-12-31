#include"StringView.h"
#include<string>
#include<iostream>

using std::string;
using std::string_view;
using std::cout;
using std::endl;

void string_before() {
	string s("abcdefghijklmnopqrstuvwxyz");
	string ss = s.substr(10, 5);  //copy string as another string

	cout << ss << endl;

}
void string_view_after() {
	string s("abcdefghijklmnopqrstuvwxyz");
	string_view sv(s);
	
	cout << sv.substr(10, 7) << endl;
}

void StringView_Test() {
	string_before();
	string_view_after();  //string_view is read-only
}