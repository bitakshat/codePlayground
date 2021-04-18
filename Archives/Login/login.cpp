
#include <iostream>
#include <conio.h>

class Login {
private:
	char pass[5];
	int size = sizeof(pass) / sizeof(pass[0]);
	int len = size;

public:
	void func(void) {
		std::cout << "Enter: ";
		char ch;
		while(len >= 1) {
			ch = _getch();
			if(ch == '\r') {
				std::cout << "\n";
				break;	
			}
			if(ch == '\b') {
				std::cout << '\b';
				pass[len-1];
				len += 1;
			}
			else {
				pass[len] = ch;
				std::cout << "*";
			}
			len -= 1;
		}
		std::cout << "\n";

		std::cout << "password: ";
		for( int x = size; x >= 1; x-- ) {
			std::cout << pass[x];
		}
		std::cout << '\n';
	}
};

int main(void){

	Login l;
	l.func();
	return 0;
}