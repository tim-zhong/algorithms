#include <iostream>
using namespace std;

// 7.8s
int fast_expo1(int a, int n) {
	int result = 1;

	while(n) {
		if(n % 2 == 1) {
			result *= a;
		}
		n /= 2;
		a *= a;
	}

	return result;
}

// 9.1s
int fast_expo2(int a, int n) {
	if(n == 0) return 1;
	
	int x = fast_expo2(a, n / 2);
	
	if(n % 2 == 0) {
		return x * x;
	} else {
		return a * x * x;
	}
}

int main() {
	cout << fast_expo1(2,3) << endl;

	for(int i = 0; i <= 100000000; i++){
		fast_expo1(i, 30);
	}

	return 0;
}