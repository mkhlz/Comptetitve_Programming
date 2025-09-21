#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define PB push_back
#define EB emplace_back
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

vector<pair<int, int>> moves;
void hanoi(int n, int from, int aux, int to) {
    if (n == 0) return;
    hanoi(n - 1, from, to, aux);
    moves.EB(from, to);
    hanoi(n -1, aux, from, to);
}

int main() {
    fastio;
    int n; cin >> n;
    hanoi(n, 1, 2, 3);
    ll k = moves.size();
    cout << k << "\n";
    for (auto &mv : moves) {
        cout << mv.first << " " << mv.second << "\n";
    }
    return 0;
}