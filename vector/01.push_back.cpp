#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;

    // Menambahkan elemen ke vector
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Menampilkan elemen
    for (int num : numbers) {
        std::cout << num << std::endl;
    }

    return 0;
}
