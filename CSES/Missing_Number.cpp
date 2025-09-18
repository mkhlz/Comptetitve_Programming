#include <bits/stdc++.h>
using namespace std;

// type aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// shortcuts
// #define pb push_back
// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define fi first
// #define se second

const ll INF = 1e18;
const int MOD = 1e9+7;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;
    
    ll n;
    cin >> n;

    ll total = n * (n + 1) / 2; // sum 1..n
    ll given_sum = 0; // accumulator for n-1
    
    for (long long i = 0; i < n - 1; ++i) {
        ll x;
        cin >> x;
        given_sum += x; // just keep accumulating
    }
    std::cout << (total - given_sum) << std::endl;
    return 0;
}