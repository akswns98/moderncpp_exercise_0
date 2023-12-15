#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <cstring>

using namespace std;

class MyApplication {
	/*
	  Implementation
	*/
public:
	MyApplication();
	MyApplication(int x);
	MyApplication(const MyApplication& other);
	MyApplication(MyApplication&& other) noexcept;
	MyApplication& operator =(const MyApplication& other);
	MyApplication& operator=(MyApplication&& other) noexcept;

};
MyApplication::MyApplication() {
	cout << __func__ << endl;
	//cout << __PRETTY_FUNCTION__ << endl;
}
MyApplication::MyApplication(int x) {
	cout << __func__ << endl;
	//cout << __PRETTY_FUNCTION__ << endl;
}
MyApplication::MyApplication(const MyApplication& other) {
	cout << __func__ << endl;
	//cout << __PRETTY_FUNCTION__ << endl;
}
MyApplication::MyApplication(MyApplication&& other) noexcept{
	cout << __func__ << endl;
	//cout << __PRETTY_FUNCTION__ << endl;
}

MyApplication& MyApplication::operator=(const MyApplication& other)
{
	// TODO: 여기에 return 문을 삽입합니다.
	cout << __func__ << endl;
	return *this;
}

MyApplication& MyApplication::operator=(MyApplication&& other) noexcept
{
	// TODO: 여기에 return 문을 삽입합니다.
	cout << __func__ << endl;
	return *this;
}

int main() {
	// print: MyApplication::MyApplication()
	MyApplication a;

	// print: MyApplication::MyApplication(const MyApplication&)
	MyApplication b = a;


	// print: MyApplication::~MyApplication()   (b destroyed)
	// print: MyApplication::~MyApplication()   (a destroyed)
	return 0;
}