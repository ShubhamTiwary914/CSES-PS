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

void dfsrun(int curr, int steps, ump<int,int> &dp){
    if(curr==0){
        if(dp.count(0))
            dp[0]=min(dp[0], steps);
        else
            dp[0] = steps;
    }
    if(curr>=1 && curr<=9){
        if(dp.count(0))
            dp[0]=min(dp[0], steps+1);
        else
            dp[0] = steps+1;
        return;
    }
    int tmp=curr;
    dp[curr]=steps;
    
    while(tmp>0){
        int d = (tmp%10);
        int newnum = (curr-d);
        //not already explored? or this path maybe smaller?
        if( (!dp.count(newnum))  && (newnum != curr) ){
            dfsrun(newnum, steps+1, dp);
        }   
        tmp/=10;
    }
}

int bfsrun(int num){
    unordered_map<int, int> dp;
    queue<pair<int,int>> qp;
    qp.push({num, 0});
    dp[0]=INT_MAX; 
    dp[num]=0;
    while(!qp.empty()){
        pair<int,int> x = qp.front();
        //first one to reach 0 wins
        if(x.ff == 0)
            return x.ss;
        else if(x.ff>=1 && x.ff<=9){
            return x.ss+1;
        }
        //else try to go wider expand
        else{
            int tmp=x.ff;
            while(tmp>0){
                int d = tmp%10;
                int nx = (x.ff - d);
                if((nx != x.ff) && !dp.count(nx)){
                    dp[nx] = x.ss+1;
                    qp.push({nx, x.ss+1}); 
                }
                tmp /= 10;
            }
        }
        qp.pop();
    }
    return dp[0];
}

void solve(){
    int num; cin>>num; 
    cout << bfsrun(num);
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