#include <iostream>
#include <vector>
#include <algorithm>  // Untuk std::reverse

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Membalik urutan elemen
    std::reverse(numbers.begin(), numbers.end());

    // Menampilkan elemen
    for (int num : numbers) {
        std::cout << num << std::endl;
    }

    return 0;
}
