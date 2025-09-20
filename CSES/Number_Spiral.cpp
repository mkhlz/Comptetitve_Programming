#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;    
    int t;
    cin >> t;
    while(t--) {
        ll y, x;
        cin >> y >> x;
        ll n = max(x, y);
        ll ans;
        if (y <= x) {
            if (x % 2 == 1) ans = x * x - y + 1;
            else ans = (x - 1) * (x - 1) + y;
        } else {
            if (y % 2 == 1) ans = (y - 1) * (y - 1) + x;
            else ans = y * y - x + 1;            
        }
        cout << ans << "\n";
    }    
    return 0;
}