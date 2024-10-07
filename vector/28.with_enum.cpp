#include <iostream>
#include <vector>

enum class Color { Red, Green, Blue };

int main() {
    std::vector<Color> colors = {Color::Red, Color::Green, Color::Blue};

    for (const auto& color : colors) {
        switch(color) {
            case Color::Red:   std::cout << "Red\n"; break;
            case Color::Green: std::cout << "Green\n"; break;
            case Color::Blue:  std::cout << "Blue\n"; break;
        }
    }

    return 0;
}
