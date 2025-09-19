#include <bits/stdc++.h>
using namespace std;

// datatypes
using ll = long long;
using str = string;
using vi  = vector<int>;

// english-y macros
#define begin_story int main() {
#define end_story return 0; }
#define say(x) cout << x
#define sayln(x) cout << x << "\n"
#define take(x) cin >> x
#define take_list(v,n) for(int i=0;i<n;++i) cin>>v[i]
#define show_list(v) for(auto &xx:v) cout<<xx<<" "; cout<<"\n"
#define loop(n) for(int i=0;i<n;++i)
#define from_to(i,a,b) for(int i=a;i<=b;++i)
#define forever while(true)
#define until(cond) while(!(cond))
#define pause cin.get()
#define newline cout << "\n"
#define big(x,y) max(x,y)
#define small(x,y) min(x,y)
#define sq(x) ((x)*(x))
#define join(a,b) a##b   // token pasting (for fun)
#define debug(x) cerr<<"[debug] "<<#x<<"="<<x<<"\n"

begin_story
    sayln("Welcome to the meme template!");
    
    say("Enter your name: ");
    str hero; take(hero);
    sayln("Nice to meet you, " + hero + "!");

    say("How many treasures did you find? ");
    int n; take(n);
    vi loot(n);
    sayln("Enter the treasures (numbers):");
    take_list(loot,n);

    say("You found: "); show_list(loot);

    sayln("The biggest treasure is: " + to_string(*max_element(loot.begin(), loot.end())));
    sayln("The smallest treasure is: " + to_string(*min_element(loot.begin(), loot.end())));

    sayln("Squares of your treasures:");
    for(auto x: loot) say(to_string(sq(x)) + " "); newline;

    sayln("Looping like a bard chanting 3 times:");
    loop(3) sayln("♪ la la la...");

    sayln("Forever loop, but I break after one song:");
    forever { sayln("🎵 infinite vibes 🎵"); break; }

    until(false) { sayln("This would never run, unless we break."); break; }

    debug(n);
    debug(hero);

end_story
