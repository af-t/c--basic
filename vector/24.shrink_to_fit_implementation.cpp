#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;

    numbers.reserve(100);  // Memesan kapasitas untuk 100 elemen
    numbers.push_back(1);
    numbers.push_back(2);

    std::cout << "Capacity before shrink_to_fit: " << numbers.capacity() << std::endl;

    // Mengecilkan kapasitas ke ukuran sebenarnya
    numbers.shrink_to_fit();

    std::cout << "Capacity after shrink_to_fit: " << numbers.capacity() << std::endl;

    return 0;
}
