#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40};

    // Menghapus elemen terakhir
    numbers.pop_back();

    // Menampilkan elemen setelah penghapusan
    for (int num : numbers) {
        std::cout << num << std::endl;
    }

    return 0;
}
