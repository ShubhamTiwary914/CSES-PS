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

#define uset unordered_set

void genGrayCodes(int curr, int n, uset<int> &dp, vc<int> &res){
    //go from 0 --> (2^n - 1)
    if(curr >= (1<<n))
        return;
    //repeated subtree
    if(dp.count(curr))
        return;
    dp.insert(curr);
    res.pb(curr);
    //set 0th to (n-1)th bits
    for(int i=0; i<n; i++){
        int newb = (curr | (1<<i));
        genGrayCodes(newb,n,dp,res);
    }
}

void printVectorBits(vc<int> &res, int n){
    for(int x: res){
        string bits(n, '0');
        int ith=0;
        while(x){
            if(x&1) 
                bits[ith]='1';
            ith++;
            x>>=1;
        }
        cout << bits << endl;
    }
}


void solve(){
    int n; cin>>n;
    vc<int> res;
    uset<int> dp;
    genGrayCodes(0,n,dp,res);

    printVectorBits(res, n);
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