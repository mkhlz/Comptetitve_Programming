#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;
    int n;
    string s;
    cin >> n;
    cin >> s;
    // already has lv
    if (s.find("lv") != string::npos) {
        std::cout << 0 << std::endl;
        return 0;
    }

    bool hasL = false, hasV = false, hasVL = false, fixableByOneReplace = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'l') hasL = true;
        if (s[i] == 'v') hasV = true;
        if (i + 1 < n) {
            if (s[i] == 'v' && s[i+1] == 'l') hasVL = true;
            // check if this pair can be fixed by just 1 replace
            if (s[i] == 'l' || s[i+1] == 'v') fixableByOneReplace = true;
        }
    }
    // case 1 - one operation is enough
    if (hasVL || hasL || hasV || fixableByOneReplace) {
        std::cout << 1 << std::endl;
        return 0;
    }
    std::cout << 2 << std::endl;
    
    return 0;
}