#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PB push_back
#define fi first
#define se second
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;
    int n; cin >> n;
    int zeros = 0, p = 5;
    // for all 5^k > n so 5, 25, 125, ...
    while (p <= n) {
        zeros += n / p;
        p *= 5;
    }
    cout << zeros << endl;
    return 0;
}

