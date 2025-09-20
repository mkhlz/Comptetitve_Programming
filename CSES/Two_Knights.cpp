#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;
    int n; cin >> n;
    for (int k = 1; k <= n; ++k) {
        ll total = (ll)k*k*(k*k-1) / 2;
        ll attacking = 4*(k-1)*(k-2);
        ll non_attacking = total - attacking; 
        cout<<non_attacking<<endl;
    }
    return 0;
}