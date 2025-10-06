// https://codeforces.com/problemset/problem/96/A
// Auth: mkhlz

#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;    
    string s; cin >> s;
    int cnt = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i-1]) {
            cnt++;
            if (cnt >= 7) {
                cout << "YES\n";
                return 0;
            }
        } else {
            cnt = 1;
        }
    }
    cout << "NO\n";
    return 0;
}