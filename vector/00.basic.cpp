#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};  // Inisialisasi dengan nilai

    // Akses elemen
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << "Element at index " << i << ": " << numbers[i] << std::endl;
    }

    return 0;
}
