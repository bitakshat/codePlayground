
// C++ program to illustrate the placement new operator
#include <iostream>

struct Students {
    std::string name;
    int age, grade;
    Students(std::string name, int age, int grade) : name{name}, age{age}, grade{grade} {}
};

int main() {
    // method 1 : for multiple objects
    char *buffer = new char[10 * sizeof(Students)];
    Students *s1 = new (&buffer[0]) Students("abc", 20, 69);
    Students *s2 = new (&buffer[8]) Students("cba", 20, 10);

    std::cout << "sizeof struct: " << sizeof(Students) << std::endl;
    std::cout << "sizeof buffer: " << sizeof(buffer) << std::endl;
    // destruct
    s1->~Students();
    s2->~Students();

    delete[] buffer;

    // method 2 : for single object
    void *memory = malloc(sizeof(Students));
    Students *a1 = new (memory) Students("xyz", 20, 34);

    std::cout << a1->name << std::endl;

    // destruct
    a1->~Students();
    free(memory);

    return 0;
}
