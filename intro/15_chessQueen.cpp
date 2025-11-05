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
typedef struct {
    vc<bool> rows;
    vc<bool> cols;
    uset<int> lrdiags;
    uset<int> rldiags;
} board;

void play(char inp[8][8], board &bb, int &res, int row, int qctr){
    //8 queens placed
    if(qctr >= 8){
        res++;
        return;
    }
    if(row>=8)
        return;
    for(int col=0; col<8; col++){
        int lrdiag = col-row, rldiag = (7-col)-row;
        //not marked & no blockers then proceed
        if( bb.rows[row] || bb.cols[col] || 
            bb.lrdiags.count(lrdiag) || bb.rldiags.count(rldiag) ||
            inp[row][col] == '*'
        )
            continue;

        //mark
        bb.rows[row]=true; bb.cols[col]=true;
        bb.lrdiags.insert(lrdiag);
        bb.rldiags.insert(rldiag);
        qctr++; 
        play(inp, bb, res, row+1, qctr);
        //unmark
        qctr--;
        bb.rows[row]=false; bb.cols[col]=false;
        bb.lrdiags.erase(lrdiag);
        bb.rldiags.erase(rldiag);
    }
}


void solve(){
    char inp[8][8];
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++)
            cin>>inp[i][j];
    }
    int res=0;
    board bb;
    bb.rows = vc<bool>(8, false);
    bb.cols = vc<bool>(8, false);

    play(inp, bb, res, 0,0);
    cout << res << endl;
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