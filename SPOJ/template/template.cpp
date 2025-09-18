#include <bits/stdc++.h>
using namespace std;

// --------- FAST I/O ----------
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)

// --------- DEBUG MACROS ----------
#ifdef LOCAL
    #define debug(x) cerr << #x << " = " << x << '\n'
    #define debugv(v) do { cerr << #v << " = ["; \
        for (auto _i : v) cerr << _i << " "; \
        cerr << "]\n"; } while(0)
#else
    #define debug(x)
    #define debugv(v)
#endif

// --------- SHORTCUTS ----------
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define ff first
#define ss second

using ll  = long long;
using pii = pair<int,int>;
using vi  = vector<int>;
using vll = vector<long long>;

// --------- CONSTANTS ----------
const int INF = 1e9;
const ll  LINF = 1e18;
const int MOD = 1e9 + 7;

// --------- SOLVE FUNCTION ----------
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    // Example debug
    debug(n);
    debugv(a);

    cout << "Sum = " << accumulate(all(a), 0LL) << "\n";
}

// --------- MAIN ----------
int main() {
    FAST_IO;
    int t = 1;
    // cin >> t;  // uncomment if multiple test cases
    while (t--) solve();
}
