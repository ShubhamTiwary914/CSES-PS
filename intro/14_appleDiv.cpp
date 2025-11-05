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
    int arr[n];
    lli ttl=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ttl += (1LL*arr[i]);
    }
    lli res=INT_MAX;
    //all combinations in 0--(2^n - 1) (max: n=20 -> 1e6 ops)
    for(int mask=0; mask<(1<<n); mask++){
        lli subsum = 0;
        for(int i=0; i<n; i++){
            if(mask&(1<<i)){
                subsum += (1LL*arr[i]);
            }
        }
        //abs diff between the two created sets
        lli remsum = (ttl - subsum);
        res = ops<lli>::imin(res, abs(subsum-remsum));
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