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
    //0=free, 1=blocker
    int grid[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char ch; cin>>ch;
            if(ch == '*') grid[i][j]=1;
            else grid[i][j]=0;
        }
    }
    lli paths[n][n];

    //traverse
    int i=0; int m=n-1;
    int row, col;
    for(int i=0; i<=m; i++){
        //left (row set, col changes)
        row=m-i;
        col=m-i;
        for(; col>=0; col--){
            if(grid[row][col]==1){
                paths[row][col]=0;
                continue;
            }
            //bottom
            if(row == m){  
                //edge
                if(col == m)
                    paths[row][col]=1; 
                else if(paths[row][col+1] == 0)
                    paths[row][col]=0;
                else
                    paths[row][col]=1;
            }
            else{
                lli val = 0;
                lli r = ( ((col+1)<=m) && (grid[row][col+1]==0) ) ? paths[row][col+1] : 0;
                lli d = ( ((row+1)<=m) && (grid[row+1][col]==0) ) ? paths[row+1][col] : 0;
                val = ((r%MOD)+ (d%MOD))%MOD;
                paths[row][col] = val;
            }
        } 
        //up (col set, row changes)
        row=m-i;
        col=m-i;
        for(; row>=0; row--){
            if(grid[row][col]==1){
                paths[row][col]=0;
                continue;
            }
            //right
            if(col == m){
                //edge
                if(row == m)
                    paths[row][col]=1; 
                else if(paths[row+1][col] == 0)
                    paths[row][col]=0;
                else
                    paths[row][col]=1;
            }
            else{
                lli val = 0;
                lli r = ( ((col+1)<=m) && (grid[row][col+1]==0) ) ? paths[row][col+1] : 0;
                lli d = ( ((row+1)<=m) && (grid[row+1][col]==0) ) ? paths[row+1][col] : 0;
                val = ((r%MOD)+ (d%MOD))%MOD;
                paths[row][col] = val;               
            }
        }
    }

    cout << paths[0][0];
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