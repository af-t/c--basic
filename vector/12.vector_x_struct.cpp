#include <iostream>
#include <vector>
#include <string>

struct Person {
    std::string name;
    int age;
};

int main() {
    std::vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35}
    };

    // Menampilkan isi vector
    for (const auto& person : people) {
        std::cout << person.name << " is " << person.age << " years old." << std::endl;
    }

    return 0;
}
