#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Mengosongkan vector
    numbers.clear();

    // Memeriksa apakah kosong
    if (numbers.empty()) {
        std::cout << "Vector is empty" << std::endl;
    } else {
        std::cout << "Vector is not empty" << std::endl;
    }

    return 0;
}
