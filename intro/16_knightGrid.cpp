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

void dfsFill(vc<vc<int>> &res, int n, int r, int c){
    intpairs paths[8] = {
        {r-2, c-1}, {r-2, c+1}, {r-1, c-2}, {r-1, c+2},
        {r+1, c-2}, {r+1, c+2}, {r+2, c-1}, {r+2, c+1}
    }; 
    for(int i=0; i<8; i++){
        //in bounds and not explored before
        int newr = paths[i].ff, newc = paths[i].ss;
        if((newr>=0 && newr<n && newc>=0 && newc<n) && 
            ((res[newr][newc]==-1) || (res[r][c]+1 < res[newr][newc])) 
        ){
            res[newr][newc] = res[r][c]+1;
            dfsFill(res, n, newr, newc);
        }
    }
}

void bfsFill(vc<vc<int>> &res, int n, int r, int c){
    queue<intpairs> coord;
    coord.push({0,0});
    while(!coord.empty()){
        int cr = coord.front().ff, cc=coord.front().ss;
        coord.pop();
        intpairs paths[8] = {
            {cr-2, cc-1}, {cr-2, cc+1}, {cr-1, cc-2}, {cr-1, cc+2},
            {cr+1, cc-2}, {cr+1, cc+2}, {cr+2, cc-1}, {cr+2, cc+1}
        };
        for(int i=0; i<8; i++){
            int newr = paths[i].ff, newc = paths[i].ss;
            if((newr>=0 && newr<n && newc>=0 && newc<n) && (res[newr][newc]==-1)){
                res[newr][newc] = res[cr][cc]+1;
                coord.push({newr, newc});
            }
        }
    }
}

void solve(){
    int n; cin>>n;
    vc<vc<int>> res(n, vc<int>(n, -1));
    res[0][0]=0;
    bfsFill(res, n, 0, 0);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << res[i][j] << " ";
        }
        ed;
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