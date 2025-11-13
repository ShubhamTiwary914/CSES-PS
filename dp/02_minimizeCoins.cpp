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
    //>input
    int m, n; cin>>m>>n;    
    int coins[m];
    for(int i=0; i<m; i++)
        cin>>coins[i];
    //*calculate
    vector<int>store(n+1, -1);
    store[0]=1;

    for(int i=1; i<=n; i++){
        bool iscoin=false;
        int val = -1;
        for(int j=0; j<m; j++){
            int coin = coins[j];
            if(coin == i){
                iscoin = true;
                break;
            }
            if((i-coin >= 0) && (store[i-coin]!=-1)){
                if(val == -1)
                    val = store[i-coin];
                else
                    val = min(val, store[i-coin]);
            }
        }
        if(iscoin){
            store[i]=1;
            continue;
        }
        if(val != -1)
            store[i] = val+1;
    }
    cout << store[n];
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