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

lli getSumm(int n){
    return 1LL*( ((1LL*n) * ((1LL*n) +1)) /2);
}

void solve(){
    int n; cin>>n;
    lli summ = getSumm(n);
    //sum is odd->can't split to two parts or <=2 (no answer)
    if((summ & 1LL) || (n<=2)){
        cout << "NO";
        return;
    } 
    lli target = summ/2;
    vc<int> s1, s2;
    lli s1sum = 0;
    //set1 sum up greedy, remains are set2
    for(int x=n; x>=1; x--){
        if((target-s1sum) >= x){
            s1sum += x;
            s1.pb(x);
        }
        else{
            s2.pb(x);
        }
    } 
    if(s1sum != target){
        cout << "NO";
        return;
    }
    cout << "YES\n";
    cout << s1.size() << endl;
    vcp(s1);
    cout << s2.size() << endl;
    vcp(s2);
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