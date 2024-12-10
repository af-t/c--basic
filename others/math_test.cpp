#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <functional>
#include <random>
#include <chrono>

using namespace std;

// Helper function to format time
string formatTime(long long milliseconds) {
    int seconds = milliseconds / 1000;
    int minutes = seconds / 60;
    int hours = minutes / 60;

    int ms = milliseconds % 1000;
    int sec = seconds % 60;
    int min = minutes % 60;

    string result;
    if (hours > 0) result += to_string(hours) + "h ";
    if (min > 0) result += to_string(min) + "m ";
    result += to_string(sec) + "s " + to_string(ms) + "ms";

    return result;
}

// Input helper function
string input(const string& prompt) {
    cout << prompt;
    string value;
    getline(cin, value);
    return value;
}

// Random number generator
int randomNumber(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void mathTest(int attempts, const function<double(double, double)>& operation, string text, int min, int max) {
    auto start = chrono::steady_clock::now();
    int correct = 0, wrong = 0;

    while (attempts-- > 0) {
        int a = randomNumber(min, max);
        int b = randomNumber(min, max); 
        if (text == " / " && b == 0) b = 1; // Avoid division by zero
        double result = operation(a, b);

        cout << a << text << b << " = ";
        double answer;
        cin >> answer;

        if (abs(answer - result) < 0.01) { // Tolerance for float comparison
            correct++;
        } else {
            wrong++;
            cout << "Incorrect! (Q: " << a << text << b
                 << "; Your Answer: " << answer
                 << ", Correct Answer: " << result << ")" << endl;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    }

    auto end = chrono::steady_clock::now();
    long long totalTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    double avgTime = static_cast<double>(totalTime) / (correct + wrong);

    cout << "\nTotal correct answers: " << correct << endl;
    cout << "Total wrong answers: " << wrong << endl;
    cout << "Total time spent: " << formatTime(totalTime) << endl;
    cout << "Average time per answer: " << formatTime(static_cast<long long>(avgTime)) << endl;

    cout << "Press Enter to continue...";
    cin.ignore();
}

int main() {
    map<int, function<double(double, double)>> operations = {
        {1, [](double a, double b) { return a + b; }},
        {2, [](double a, double b) { return a - b; }},
        {3, [](double a, double b) { return a * b; }},
        {4, [](double a, double b) { return round((a / b) * 100) / 100; }} // Rounded to 2 decimal places
    };
    map<int, string> texts = {
        {1, " + "},
        {2, " - "},
        {3, " * "},
        {4, " / "}
    };

    while (true) {
        cout << "\033[2J\033[1;1H"; // Clear screen (ANSI escape codes)
        cout << "\nSelect the type of test:" << endl;
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "5. Exit" << endl;

        int choice = stoi(input("Enter your choice (1-5): "));
        if (choice == 5) {
            cout << "\nGoodbye!" << endl;
            break;
        }

        if (operations.find(choice) == operations.end()) {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        int attempts = stoi(input("Enter the number of attempts: "));
        if (attempts <= 0) {
            cout << "Invalid number of attempts. Please try again." << endl;
            continue;
        }

        int min = stoi(input("Enter the minimum range: "));
        int max = stoi(input("Enter the maximum range: "));
        if (min > max) {
            cout << "Invalid range. Minimum should be less than or equal to maximum. Please try again." << endl;
            continue;
        }

        mathTest(attempts, operations[choice], texts[choice], min, max);
    }

    return 0;
}
