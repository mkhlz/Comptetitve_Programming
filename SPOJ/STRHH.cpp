#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;
    
    int t;
    cin >> t; // number of test cases
    while (t--) {
        string s;
        cin >> s; // read the string
        int n = s.size();
        int half = n / 2; // first half only
        // now pick every second char
        for (int i = 0; i < half; i += 2) {
            cout << s[i];
        }
        cout << "\n";
    }
    
    return 0;
}