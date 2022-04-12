#include <iostream>
#include <fstream>

int main(void) {
	std::ostream readFile;

	readFile.open('./code.cc');
	
	readFile.close();

	return 0;
}
