#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MAX_N 10001
#define MOD 1000000007
#define apo(a,b) sqrt( powl(a.x-b.x,2) + powl(a.y-b.y,2) )
#define ldeq(a,b) ( fabsl(a-b) < 0.0000000007 )
#define mmodeq(a,b) ((a>=0)?((a%b)%b):((((a+((abs(a)+b)/b)*b))%b)%b))
#define rep(a,b) for(int i=a; i<=b; ++i)
#define repv(a,b,i) for(int i=a; i<=b; ++i)
#define ALL(x) (x).begin(), (x).end()
#define S(x) ((int)(x).size())
#define PB push_back
#define fi first
#define se second
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


int main() {
    fastio;
    
    int a, b, c;
    cin >> a >> b >> c;
    int travel = a + b;
    int latest_start = c - travel;
    cout << latest_start << "\n";
    
    return 0;
}