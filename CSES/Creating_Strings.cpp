#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define SORT(s) sort(s.begin(), s.end());
#define PB push_back
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;
    string s; if(!(cin >> s)) return 0; // be sure to start from smallest
    SORT(s);
    vector<string> ans;
    do {
        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    // output
    cout << ans.size() << "\n";
    for (auto &t : ans) {
        cout << t << "\n";
    }
    return 0;
}