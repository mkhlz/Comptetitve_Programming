#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PB push_back
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;
    int n;cin>>n;
    ll total = (ll)n * ( n + 1) / 2;
    if (total % 2 != 0) { cout << "NO" << endl; return 0; }
    cout << "YES" << endl;
    ll target = total / 2;
    vector<int> set1, set2;
    for(int i = n; i >= 1; --i) {
        if (target >= i) {
            set1.PB(i);
            target -= i;
        } else {
            set2.PB(i);
        }
    }
    // output set1
    cout << set1.size() << endl;
    for (auto num : set1) {
        cout << num << " ";
    }
    cout << endl;
    // output set2
    cout << set2.size() << endl;
    for (auto num : set2) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

