#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 4, 5};

    // Menyisipkan elemen di posisi tertentu (index 2)
    numbers.insert(numbers.begin() + 2, 3);

    // Menghapus elemen di posisi tertentu (index 3)
    numbers.erase(numbers.begin() + 3);

    // Menampilkan hasil
    for (int num : numbers) {
        std::cout << num << std::endl;
    }

    return 0;
}
