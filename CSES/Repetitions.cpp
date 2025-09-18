#include <bits/stdc++.h>
using namespace std;

// type aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

const ll INF = 1e18;
const int MOD = 1e9+7;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;
    
    string s;
    cin >> s;
    int maxlen = 1, currlen = 1;
    char currChar = s[0]; // init w first read char
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == currChar) currlen++;
        else {
            maxlen = max(maxlen, currlen); // update max if needed
            currChar = s[i]; // switch to new char
            currlen = 1; // reset current length
        }
    }
    maxlen = max(maxlen, currlen);
    std::cout << maxlen << std::endl;
    return 0;
}