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

void makeStr(string ss, vc<bool> &picked, string curr, set<string> &res){
    int n = ss.length();
    if(curr.length() == n){
        res.insert(curr);
        return;
    }
    for(int i=0; i<n; i++){
        if(picked[i])
            continue;
        //pick case
        picked[i]=true;
        curr += ss[i];
        makeStr(ss,picked,curr,res);
        //dont pick case
        picked[i]=false;
        if(!curr.empty())
            curr.pop_back();
    }
}

void solve(){
    string ss; cin>>ss;
    int n = ss.length(); 
    vc<bool> picked(n);
    set<string> res;

    makeStr(ss, picked, "", res);
    cout << res.size() << endl;
    for(string st: res){
        cout << st << endl;
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