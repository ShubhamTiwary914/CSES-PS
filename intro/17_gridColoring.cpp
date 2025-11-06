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

void bfsFill(vc<vc<char>> &grid, vc<vc<bool>> &vis, int rs, int cs){
    queue<intpairs> coords;
    coords.push({0,0});
    while(!coords.empty()){
        //mark A,B,C,D as true,false
        vc<bool> mark(4,true);
        intpairs head = coords.front(); coords.pop();
        int r = head.ff, c = head.ss;
        if(vis[r][c])
            continue;
        vis[r][c]=true;
        //dont use the current value
        char ch = grid[r][c];
        mark[(int)(ch-'A')]=false;
        //check adj top & left to not use those
        vc<intpairs> adjs = {{r-1,c}, {r,c-1}};
        for(int i=0; i<2; i++){
            int rprev = adjs[i].ff, cprev = adjs[i].ss;
            if(rprev>=0 && rprev<rs && cprev>=0 && cprev<cs){
                ch = grid[rprev][cprev];
                mark[ch-'A']=false;
            }
        }
        //check what can be used, use that
        for(int i=0; i<4; i++){
            if(mark[i]){
                ch = (char)(i + (int)('A'));
                grid[r][c] = ch;
                break;
            }
        }
        //next grid if in bounds
        vc<intpairs> newcoords = {{r,c+1}, {r+1,c}};
        for(int i=0; i<2; i++){
            int newr = newcoords[i].ff, newc = newcoords[i].ss;
            if(newr>=0 && newr<rs && newc>=0 && newc<cs){
                if(!vis[newr][newc]){
                    coords.push({newr,newc});
                }
            }
        }
    }
}


void solve(){
    int rs, cs; cin>>rs>>cs;
    vc<vc<char>> grid(rs, vc<char>(cs));
    for(int i=0; i<rs; i++){
        for(int j=0; j<cs; j++)
            cin>>grid[i][j];
    }
    vc<vc<bool>> vis(rs, vc<bool>(cs, false));
    
    bfsFill(grid, vis, rs, cs);
    for(int i=0; i<rs; i++){
        for(int j=0; j<cs; j++)
            cout << grid[i][j];
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