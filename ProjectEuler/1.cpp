#include <iostream>

int main() {
    int sum = 0;
    // Loop through numbers below 1000
    for (int i = 1; i < 1000; ++i) {
        // Check if the number is divisible by 3 or 5
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i; // Add to sum
        }
    }
    std::cout << "Sum: " << sum << std::endl; // Output the result
    return 0;
}
