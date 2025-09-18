#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;
    
    long long n;
    cin >> n;
    cout << n;
    // continue the process until n becomes 1
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        std::cout << " " << n;
    }
    std::cout << std::endl;
    
    return 0;
}