#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;

    string s;
    cin >> s;

    int count = 0;
    for (auto elem : s) {
        if (elem == '1') count++;
    }

    std::cout << count << std::endl;

    
    return 0;
}