#include <iostream>
#include <vector>

int main() {
    std::vector<int> source = {1, 2, 3, 4, 5};
    std::vector<int> destination;

    // Memindahkan elemen dari 'source' ke 'destination'
    destination = std::move(source);

    // Menampilkan hasil
    std::cout << "Destination contains: ";
    for (const int& num : destination) {
        std::cout << num << " ";
    }

    std::cout << "\nSource is now empty: " << source.size() << std::endl;

    return 0;
}
