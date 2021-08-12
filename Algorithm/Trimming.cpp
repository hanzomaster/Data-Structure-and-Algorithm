#include <iostream>
#include <string>
using namespace std;

// Xoá các kí tự không mong muốn trong phần đầu và cuối của string
string inline &trimString(string &str, string &chars) {
	str.erase(0, str.find_first_not_of(chars));// Xoá phần cuối
	str.erase(str.find_last_not_of(chars) + 1);// Xoá phần đầu
	return str;
}

int main() {
	string char_to_trim = ".,/ ";
	string text = ",.,/   C++ Standard ,.,/";

	cout << text << endl;
	trimString(text, char_to_trim);
	cout << text << endl;
	return 0;
}
