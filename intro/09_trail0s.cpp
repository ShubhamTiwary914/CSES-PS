//INCOMPLETE-----
//--------------
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

lli exp5(int n){
    lli res=1;
    lli coeff = 5;
    while(n){
        if(n&1){
            res *= coeff;
        }
        coeff *= coeff;
        n>>=1;
    }
    return res;
}

void solve(){
    int n; cin>>n;
    int m5e = (log(n)/log(5));
    lli e5 = exp5(m5e);

    int prevdivs=0;
    int res=0;
    int coeff=m5e;
    while(e5>=5){
        int divs = ((1LL*n)/e5);
        int currdivs = (divs-prevdivs);
        res += currdivs*(coeff--);
        prevdivs += currdivs;
        e5/=5;
    }
    cout << res;
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