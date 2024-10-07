#include <iostream>
#include <vector>
#include <algorithm>  // Untuk std::sort dan std::unique

int main() {
    std::vector<int> numbers = {1, 2, 2, 3, 4, 4, 5};

    // Sortir elemen
    std::sort(numbers.begin(), numbers.end());

    // Menghapus elemen duplikat
    auto last = std::unique(numbers.begin(), numbers.end());
    numbers.erase(last, numbers.end());

    // Menampilkan hasil
    for (int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}
