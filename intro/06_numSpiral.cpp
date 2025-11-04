#include<bits/stdc++.h>
#define lli long long int
#define ump unordered_map
#define pq priority_queue
#define pqmin(type) priority_queue<type, vector<type>, greater<type>>
#define intpairs pair<int,int>
#define ff first
#define ss second
#define vc vector
#define pb push_back
#define ed cout<<endl
using namespace std;
template <typename num>
struct ops {
    static num imax(num x, num y) { return (x>y)?x:y; }
    static num imin(num x, num y) { return (x<y)?x:y; }
};
void vcp(vc<int> &a){ for(int x: a) cout << x << ' '; cout << endl; }
void vcpp(vc<intpairs> &a){ for(intpairs x: a) cout << x.ff << ' ' << x.ss << endl; cout << endl; }
void ppp(intpairs &p){ cout << p.ff << ' ' << p.ss << endl; }
const int MOD=1e9+7;

void solve(){
    int n; cin>>n;
    while(n--){
        int x, y; cin>>x>>y;
        //move diagonally
        int m = max(x,y);
        int steps = (m-1);
        lli val = 1LL + (1LL*steps)*(1LL*steps + 1LL);
        //at diagnal answer -> stop
        if(x==y){
            cout << val << endl;
            continue;
        }
        //odd pattern
        if(m&1){
            if(m!=x) //row up, incr
                val += 1LL*abs(m-x);
            else //col left, dec
                val -= 1LL*abs(m-y);
        }
        else{
            if(m!=x) //row up, dec
                val -= 1LL*abs(m-x);
            else //col left, incr
                val += 1LL*abs(m-y);
        }
        cout << val << endl;
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}