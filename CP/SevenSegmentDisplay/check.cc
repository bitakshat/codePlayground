#include <iostream>
#include <limits>
#include <string>
#include <limits>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// int exit = 0;
	// do {
	// 	std::cout << "Insert a character: ";
	// 	char character = getchar();
	// 	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// 	if(character == 'a') {
	// 		std::cout << "valid character...\n";
	// 	} else {
	// 		std::cout << "Invalid Character...\n";
	// 		exit = 1;
	// 	}
	// } while(exit == 0);

	printf("Enter a character: ");
	char character = getchar();
	printf("You entered %s: ", character);

	return 0;
}
