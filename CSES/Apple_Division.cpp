#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define PB push_back
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

ll n, ans = LLONG_MAX;
vector<ll> a;

void dfs (int i, ll sum1, ll sum2) {
    if (i == n) {
        ans = min(ans, llabs(sum1 - sum2));
        return;
    }
    dfs(i+1, sum1 + a[i], sum2);
    dfs(i+1, sum1, sum2 + a[i]);
}

int main() {
    fastio;
    cin >> n;
    a.resize(n);
    for(auto &x : a) cin >> x;
    dfs(0,0,0);
    cout << ans;
}