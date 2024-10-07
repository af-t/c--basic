#include <iostream>
#include <vector>

int main() {
    // Membuat vector 2D 3x3
    std::vector<std::vector<int>> matrix(3, std::vector<int>(3));

    // Inisialisasi elemen
    int value = 1;
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            matrix[i][j] = value++;
        }
    }

    // Menampilkan matriks
    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
