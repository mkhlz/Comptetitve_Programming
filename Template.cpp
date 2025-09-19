# Modern & Compact C++ Template

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
constexpr int MAX_N = 10001;
constexpr int MOD = 1000000007;
constexpr ld EPS = 1e-9;
inline ld distance2D(ld x1, ld y1, ld x2, ld y2){return sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));}
inline bool equal_ld(ld a, ld b){return fabsl(a-b)<EPS;}
inline int modfix(int a,int b){return (a%b+b)%b;}
#define rep(i,a,b) for(int i=a;i<b;++i)
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define fi first
#define se second
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);

int main(){
    fastio;
    vector<int> v={3,1,2};
    sort(ALL(v));
    for(int x:v) cout<<x<<" ";
    cout<<"\n";
    cout<<modfix(-3,5)<<"\n";
    cout<<distance2D(0,0,3,4)<<"\n";
}
```
