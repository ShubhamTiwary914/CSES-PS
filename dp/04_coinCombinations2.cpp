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
    int m, n;
    cin>>m>>n;
    vector<int> coins(m);
    for(int i=0; i<m; i++)
        cin>>coins[i];
    //n items, each defining if sum starts with coin
    vector<vector<lli>> dp(n+1, vector<lli>(m, 0));
    vector<lli> init0(m, 1);
    dp[0]=init0;

    //calculate
    for(int i=1; i<=n; i++){
        vector<lli> tmp(m);
        for(int j=0; j<m; j++){
            int c = coins[j];
            int id = i-c;
            if(id>=0){
                if(id==0){
                    tmp[j]++;
                    tmp[j] = tmp[j]%MOD;
                }
                else{
                    for(int k=j; k<m; k++){
                        tmp[k] = ((tmp[k]%MOD) + (dp[id][k]%MOD))%MOD;
                    }
                }
            }
        }
        // ed;
        dp[i]= tmp;
    }
    for(int i=0; i<=n; i++){
        cout << i << "    ";
        for(int x: dp[i])
            cout << x << " ";
        ed;
    }
    lli res=0;
    for(lli x: dp[n])
        res = ((res%MOD) + (x%MOD))%MOD;
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