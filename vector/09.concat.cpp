#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};

    // Menggabungkan vec2 ke vec1
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());

    // Menampilkan hasil
    for (int num : vec1) {
        std::cout << num << std::endl;
    }

    return 0;
}
