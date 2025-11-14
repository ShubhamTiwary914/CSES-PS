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
    int cn, num;
    cin>>cn>>num;
    int coins[cn];
    for(int i=0; i<cn; i++)
        cin>>coins[i];

    lli res[num+1];
    res[0]=1;
    for(int i=1; i<=num; i++){
        lli val = 0;
        for(int j=0; j<cn; j++){
            int coin = coins[j];
            if((i-coin) >= 0){
                val = ((val%MOD) + (res[i-coin]%MOD))%MOD;    
            }
        }
        res[i]=val;
    }
    cout << res[num];
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