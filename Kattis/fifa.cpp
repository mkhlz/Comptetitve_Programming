#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;
    
    long long n, k;
    cin >> n >> k;
    long long years_passed = n / k;
    std::cout << 2022 + years_passed << std::endl;
    
    return 0;
}