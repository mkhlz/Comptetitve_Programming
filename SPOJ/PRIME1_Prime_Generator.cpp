#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// get all primes upto sqrt of n
vector<int> simpleSieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i])
            primes.push_back(i);
    }
    return primes;
}

// segmented sieve to find primes in range [m, n]
vector<int> segmentedSieve(int m, int n) {
    int limit = (int)floor(sqrt(n)) + 1;
    vector<int> primes = simpleSieve(limit);
    vector<bool> isPrime(n - m + 1, true);
    if (m == 1) isPrime[0] = false; // 1 is not prime
    for (auto prime : primes) {
        int start = max(prime * prime, ((m + prime - 1) / prime) * prime);
        for (int j = start; j <= n; j += prime) {
            isPrime[j - m] = false;
        }
    }
    vector<int> result;
    for (int i = 0; i <= n - m; i++) {
        if (isPrime[i]) result.push_back(i + m);
    }
    return result;
}

int main() {
    fastio;
    
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        vector<int> primes = segmentedSieve(m, n);
        for (int p : primes) cout << p << "\n";
        if (t) cout << "\n"; // only add blank line between test cases
    }
    return 0;
}