#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;
    
    int a,b,c,x;
    cin>>a>>b>>c>>x;
    int cnt = 0;
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            int rem = x - 500*i - 100*j; // left after using i, j
            if (rem >= 0 && rem % 50 == 0 && rem/50 <= c) cnt++;
        }
    }
    std::cout << cnt << std::endl;
    
    return 0;
}