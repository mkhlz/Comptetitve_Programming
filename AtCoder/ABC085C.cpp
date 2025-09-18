#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;
    
    int N, Y;
    cin >> N >> Y; 
    
    // brute force all possible x (10000 bills)
    // and y (5000) bills
    for (int x = 0; x <= N; x++) {
        for (int y = 0; y <= N - x; y++) {
            int z = N - x - y; // remaining are 1000 bills
            // check total
            int total = 10000*x + 5000*y + 1000*z;
            if (total == Y) {
                std::cout << x << " " << y << " " << z << std::endl;
                return 0;
            }
        }
    }
    std::cout << "-1 -1 -1" << std::endl;
    return 0;
}