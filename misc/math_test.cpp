#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <functional>
#include <random>
#include <chrono>
#include <limits>
#include <sstream>

// Use enum class for operation types
enum class Operation {
  Addition,
  Subtraction,
  Multiplication,
  Division
};

// Use named constants for clarity
const int MAX_ATTEMPTS = 1000;
const int MIN_RANGE_DEFAULT = -1000000;
const int MAX_RANGE_DEFAULT =  1000000;

// Helper function to format time using chrono's formatting capabilities
std::string formatTime(long long milliseconds) {
    auto duration = std::chrono::milliseconds(milliseconds);
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
    duration -= seconds;
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(seconds);
    seconds -= minutes;
    auto hours = std::chrono::duration_cast<std::chrono::hours>(minutes);
    minutes -= hours;

    std::stringstream ss;
    if (hours.count() > 0) ss << hours.count() << "h ";
    if (minutes.count() > 0) ss << minutes.count() << "m ";
    ss << seconds.count() << "s " << duration.count() << "ms";
    return ss.str();
}

// Input helper function with improved validation
double inputNumber(const std::string& prompt, int min = std::numeric_limits<int>::min(), int max = std::numeric_limits<int>::max()) {
    std::string line;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        double value;
        if (ss >> value && ss.eof() && value >= min && value <= max) {
            return value;
        } else {
            std::cout << "Invalid input. Please enter a number between " << min << " and " << max << ".";
            //Clear error flags
            //std::cin.clear();
            //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}


// Random number generator
int randomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void mathTest(int attempts, const std::function<double(double, double)>& operation, const std::string& text, int min, int max) {
    auto start = std::chrono::steady_clock::now();
    int correct = 0;
    int wrong = 0;

    for (int i = 0; i < attempts; ++i) {
        int a = randomNumber(min, max);
        int b = randomNumber(min, max);
        if (text == " / " && b == 0) b = 1; // Avoid division by zero

        double result = operation(a, b);
        std::cout << a << text << b << " = ";
        double answer = inputNumber("", std::numeric_limits<int>::min(), std::numeric_limits<int>::max());


        if (std::abs(answer - result) < 0.01) {
            correct++;
        } else {
            wrong++;
            std::cout << "Incorrect! (Q: " << a << text << b
                      << "; Your Answer: " << answer
                      << ", Correct Answer: " << result << ")" << std::endl;
        }
    }

    auto end = std::chrono::steady_clock::now();
    long long totalTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    double avgTime = static_cast<double>(totalTime) / (correct + wrong);

    std::cout << "\nTotal correct answers: " << correct << std::endl;
    std::cout << "Total wrong answers: " << wrong << std::endl;
    std::cout << "Total time spent: " << formatTime(totalTime) << std::endl;
    std::cout << "Average time per answer: " << formatTime(static_cast<long long>(avgTime)) << std::endl;

    std::cout << "Press Enter to continue...";
    std::cin.ignore();
}

int main() {
    std::map<Operation, std::function<double(double, double)>> operations = {
        {Operation::Addition, [](double a, double b) { return a + b; }},
        {Operation::Subtraction, [](double a, double b) { return a - b; }},
        {Operation::Multiplication, [](double a, double b) { return a * b; }},
        {Operation::Division, [](double a, double b) { return static_cast<double>(static_cast<long long>((a / b) * 100)) / 100; }}
    };
    std::map<Operation, std::string> texts = {
        {Operation::Addition, " + "},
        {Operation::Subtraction, " - "},
        {Operation::Multiplication, " * "},
        {Operation::Division, " / "}
    };

    while (true) {
        std::cout << "\033[2J\033[1;1H"; // Clear screen
        std::cout << "\nSelect the type of test:" << std::endl;
        std::cout << "1. Addition (+)" << std::endl;
        std::cout << "2. Subtraction (-)" << std::endl;
        std::cout << "3. Multiplication (*)" << std::endl;
        std::cout << "4. Division (/)" << std::endl;
        std::cout << "5. Exit" << std::endl;

        int choice = static_cast<int>(inputNumber("Enter your choice (1-5): ", 1, 5));
        if (choice == 5) {
            std::cout << "\nGoodbye!" << std::endl;
            break;
        }

        Operation op = static_cast<Operation>(choice - 1);
        int attempts = static_cast<int>(inputNumber("Enter the number of attempts (1-" + std::to_string(MAX_ATTEMPTS) + "): ", 1, MAX_ATTEMPTS));
        int min = static_cast<int>(inputNumber("Enter the minimum range (" + std::to_string(MIN_RANGE_DEFAULT) + "-): ", MIN_RANGE_DEFAULT));
        int max = static_cast<int>(inputNumber("Enter the maximum range (->" + std::to_string(MAX_RANGE_DEFAULT) + "): ", min, MAX_RANGE_DEFAULT));


        mathTest(attempts, operations[op], texts[op], min, max);
    }

    return 0;
}
