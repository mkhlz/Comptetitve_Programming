#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

#ifdef LOCAL
    #define debug(x) cerr << #x << " = " << (x) << endl
#else
    #define debug(x)
#endif

void solve() {
    int x;
    while (cin >> x) {   // keep reading input
        if (x == 42)     // stop when 42 comes
            break;
        cout << x << "\n"; // print other numbers
    }
}

int main() {
    fastio;             // enable fast IO
    solve();            // run the solution
    return 0;
}
