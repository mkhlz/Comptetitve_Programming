#include <iostream>
using namespace std;

int main() {
    // Initialize the first two even Fibonacci numbers
    int a = 2, b = 8;
    int sum = 0;

    // Add the first even Fibonacci number to the sum
    sum += a;

    // Loop until the next even Fibonacci number exceeds 4 million
    while (b <= 4000000) {
        // Add the current even Fibonacci number to the sum
        sum += b;
        // Update to the next even Fibonacci number
        int next = 4 * b + a;
        a = b;
        b = next;
    }

    // Output the total sum
    cout << "Sum of even Fibonacci numbers: " << sum << endl;
    return 0;
}
