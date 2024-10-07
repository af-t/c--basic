#include <iostream>
#include <vector>
#include <algorithm>  // Untuk std::find

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    int search;
    std::cout << "Number to search: ";
    std::cin >> search;

    // Mencari elemen
    auto it = std::find(numbers.begin(), numbers.end(), search);

    if (it != numbers.end()) {
        std::cout << "Element found at index: " << std::distance(numbers.begin(), it) << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}
