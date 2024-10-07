#include <iostream>
#include <vector>
#include <numeric>  // Untuk std::accumulate

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Menjumlahkan semua elemen
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    std::cout << "Total sum: " << sum << std::endl;

    return 0;
}
