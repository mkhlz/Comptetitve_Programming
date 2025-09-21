#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

ll mod_exp(ll b, ll e) {
    ll res = 1;
    while (e) {
        if (e & 1) res = res * b % MOD;
        b = b * b % MOD;
        e >>= 1; 
    }
    return res;
}

int main() {
    fastio;
    ll n; cin >> n;
    cout << mod_exp(2, n) << endl;    
    return 0;
}