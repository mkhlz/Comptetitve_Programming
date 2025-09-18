// the problem is very simple, there are some cards on a table
// two players Alice and Bob are playing and picking cards one
// after the other. Alice goes first. The mathematical jargon
// makes things look scary but really the key point here is
// the cards can be picked any how, not necessary that the
// player has to pick the last card

// so the problem boils down to sorting the cards in descending
// order and then Alice will get the odd cards and Bob, the even
// ones. Getting the difference of the totals of each is our result

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    fastio;
    
    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    // sort descending
    sort(a.begin(), a.end(), greater<long long>());
    long long alice = 0, bob = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) alice += a[i];
        else bob += a[i];
    }
    std::cout << alice - bob << std::endl;
    return 0;
}