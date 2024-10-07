#include <iostream>
#include <vector>
#include <algorithm>  // Untuk std::count_if

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Menghitung elemen yang lebih besar dari 5
    int count = std::count_if(numbers.begin(), numbers.end(), [](int x){ return x > 5; });

    std::cout << "Jumlah elemen lebih besar dari 5: " << count << std::endl;

    return 0;
}
