#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;
    
    int a, b;
    cin >> a >> b;
    if ((a % 2 == 0) || (b % 2 == 0)) cout << "Even\n";
    else cout << "Odd\n";
    
    return 0;
}