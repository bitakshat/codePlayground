#include <iostream>
#include <vector>
#include <typeinfo>

#define lint long long int
#define itr(a, b) for (int a = 0; a < b; a++)
#define dbg(var) std::cout << (#var) << ": " << var << '\n'
#define out(var) std::cout << (#var);

int *maximaOrMinima(int value, int *MMAR) {

	int arr[4] = {};
	int iterator = 0;
	while (value != 0) {
		int n = value % 10;
		arr[iterator] = n;
		iterator += 1;
		value /= 10;
	}

	int itrSize = sizeof(arr) / sizeof(arr[0]);
	// std::cout << arr[0];
	for (int i = 1; i <= itrSize; i++) {
		if (i > itrSize) break;	
		// std::cout << arr[i-1] << " ";
		(arr[i-1] > arr[i]) ? MMAR[0] = 1 : MMAR[0] = 0;
	 	(arr[i+1] < arr[i]) ? MMAR[0] = 1 : MMAR[0] = 0;
	}
	// std::cout << '\n';
	return MMAR;
}

// returning vector from function
std::vector<int> returnVector(int data) {
	std::vector<int>::iterator vecItr;
	std::vector<int> vecStore;

	vecStore.push_back(data);
	return vecStore;
}

int sumOfSlope(int a, int b) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<int> n;
	for (int x = a; x <= b; x++) {
		n.push_back(x);
	}

	std::vector<int>::iterator itr;
	int count = 0;
	int MMAR[2] = {0, 0};
	for (itr = n.begin(); itr != n.end(); itr++) {
		int *valueStore = maximaOrMinima(*itr, MMAR);
		count += 1;
		std::cout << *(valueStore + 0) << " : " << *(valueStore + 1) << '\n';
	}
	dbg(count);
	return 0;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int r1, r2;
//	std::cin >> r1 >> r2;
//	sumOfSlope(r1, r2);

	static std::vector<int> vec;
	std::vector<int>::iterator vecItr;
	for (auto x = 0; x < 10; x++) vec = returnVector(x);
	for (vecItr = vec.begin(); vecItr != vec.end(); vecItr++) std::cout << *vecItr << " ";


	return EXIT_SUCCESS;
}
