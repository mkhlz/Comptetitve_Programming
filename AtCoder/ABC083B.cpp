#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int digit_sum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10; // add last digit
        x /= 10; // remove last digit
    }
    return sum;
}


int main() {
    fastio;
    
    int N,A,B;
    cin>>N>>A>>B;
    int total = 0;
    for (int i = 1; i <= N; i++) {
        int sum_digits = digit_sum(i);
        // add total to number if digit sum is within range
        if (sum_digits >= A && sum_digits <= B) total += i;
    }
    std::cout << total << std::endl;
    return 0;
}