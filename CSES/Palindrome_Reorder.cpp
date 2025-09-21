#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define PB push_back
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;
    string s; cin >> s;
    vector<int> c(26);
    for(auto x:s) c[x-'A']++;
    int odd = 0, mid = -1;
    for (int i = 0; i < 26; ++i)
    if (c[i] & 1) odd++, mid = i;
    if (odd > 1) { cout << "NO SOLUTION\n"; return 0; }
    string a = "";
    for (int i=0; i<26; ++i) a += string(c[i]/2, 'A' + i);
    string b = a; reverse(b.begin(), b.end());
    if (mid != -1) cout << a << char('A' + mid) << b;
    else cout << a << b;
    return 0;
}