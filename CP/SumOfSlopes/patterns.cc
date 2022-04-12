#include <bits/stdc++.h>

void pattern1(void) {
	for (int i = 0; i < 5; i++) {
		for (int x = i; x < 5; x++) {
			std::cout << "*";
		}
		std::cout << '\n';
	}
}

void pattern2(void) {
	for (int i = 5; i >= 0; i--) {
		for (int x = i; x < 5; x++) {
			std::cout << "*";
		}
		std::cout << '\n';
	}
}

void pattern3(void) {
	int n = 5;
	for (int i = n; i >= 1; i--) {
		for (int j = i; j >= 2; j--) {
			std::cout << " ";
		}
		for (int k = 1; k <= 2*(n - i + 1) - 1; k++) {
			std::cout << "*";
		}
		std::cout << '\n';
	}
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	
	std::cout << "Pattern 1" << std::endl;
	pattern1();
	std::cout << "Pattern 2" << std::endl;
	pattern2();	
	std::cout << "Pattern 3" << std::endl;
	pattern3();
	return EXIT_SUCCESS;
}
