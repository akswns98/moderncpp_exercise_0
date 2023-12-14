#include <iostream>
using namespace std;


constexpr int max(int a, int b) {
	if (a == 1 && b == 1)
		return 1;
	int temp = 0;
	for (int i = 1; i <= a; i++) {
		if (((a % i) == 0) && ((b % i) == 0))
		{
			temp = i;
		}
	}
	return temp;

}


int main() {
	constexpr int a = 20;;
	constexpr int b = 30;

	constexpr int c = max(a, b);

	cout << c << endl;

	return 0;

}