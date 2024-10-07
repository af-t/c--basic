#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50};

    // Menggunakan reverse_iterator untuk iterasi mundur
    for (std::vector<int>::reverse_iterator it = numbers.rbegin(); it != numbers.rend(); ++it) {
        std::cout << "Element: " << *it << std::endl;
    }

    return 0;
}
