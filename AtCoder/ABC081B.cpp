#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = INT_MAX;
    for (auto x : a) {
        // count trailing zeros in binary
        int c = __builtin_ctz(x);
        ans = min(ans, c);
    }
    std::cout << ans << std::endl;
    return 0;
}