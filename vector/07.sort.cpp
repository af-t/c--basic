#include <iostream>
#include <vector>
#include <algorithm>  // Untuk std::sort

int main() {
    std::vector<int> numbers = {4, 2, 5, 1, 3};

    // Sortir elemen
    std::sort(numbers.begin(), numbers.end());

    // Menampilkan elemen
    for (int num : numbers) {
        std::cout << num << std::endl;
    }

    return 0;
}
