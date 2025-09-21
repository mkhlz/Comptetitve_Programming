#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define PB push_back
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;
    int n; cin >> n;
    int total = 1 << n; // 2^n
    for (int i = 0; i < total; ++i) {
        int gray = i ^ (i >> 1);
        for (int j = n - 1; j >= 0; j--) {
            cout << ((gray >> j) & 1);
        }
        cout << "\n";
    }
    return 0;
}