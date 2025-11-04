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
    string ss; cin>>ss;
    //count chars
    int n = ss.length();
    vc<int> ctr(26, 0);
    for(char ch: ss){
        ctr[(int)(ch-'A')]++;
    }
    //find center id and extra char
    char extra; int mid=(n/2);
    bool extrause= (n&1);
    bool extrafound=false;
    vc<char> res(n);
    
    for(char ch='A'; ch<='Z'; ch++){
        if(ctr[ch-'A'] & 1){
            if(extrafound){
                cout << "NO SOLUTION";
                return;
            }
            extra = ch;
            ctr[ch-'A']--;
            extrafound=true;
        }
    }
    if(extrause)
        res[mid]=extra;
    
    //make palindrome
    int i=0, j=n-1, k=0;
    while(i<j){
        while(ctr[k]<=0)
            k++;
        res[i] = (char)(k + (int)'A');
        ctr[k]--;
        res[j] = (char)(k + (int)'A');
        ctr[k]--;
        i++;
        j--;
    }
    for(char ch: res)
        cout << ch;
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