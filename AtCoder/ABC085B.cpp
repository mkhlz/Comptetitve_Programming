// if diameters are 10, 8, 8, 6 then distinct diameters are
// 10, 8, 6 --> 3 layers

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;
    
    int N;
    cin >> N;
    set<int> s;
    for (int i = 0; i < N; i++) {
        int d;
        cin >> d;
        s.insert(d);
    }
    // number of distinct items = stack height
    std::cout << s.size() << std::endl;
    
    return 0;
}