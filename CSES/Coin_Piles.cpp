#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define PB push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;
    int t; cin >> t;
    while (t--)
    {
        ll a, b; cin >> a >> b;
        if (a > b) swap(a, b); // ensure b is the bigger one
        bool cond1 = (a + b) % 3 == 0; // total divisible by 3 ?
        bool cond2 = (b <= 2 * a); // larger pile not more than 2x smaller
        if (cond1 && cond2) YES;
        else NO;
    }
    return 0;
}