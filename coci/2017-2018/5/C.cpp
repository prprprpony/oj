#include<bits/stdc++.h>
using namespace std;
#define ALL(a) begin(a), end(a)
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define RP(i,n) REP(i,0,n)
#define PB push_back
template<class T>
bool cmin(T&a,const T&b) {return b < a ? a = b, 1 : 0;}
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
template<class T,class U>
pair<T,U> operator + (const pair<T,U> & a,const pair<T,U> & b)
{
    return {a.F+b.F,a.S+b.S};
}
template<class T,class U>
pair<T,U> operator += (pair<T,U> & a,const pair<T,U> & b)
{
    return a = a + b;
}
const int N = 2e5+87;
vector<int> g[N];
ll ans[N];
int dfs(int u)
{
    int now = 0;
    for (int v : g[u]) {
        int t = dfs(v);
        ans[u] += ans[v] + t;
        now += t;
    }
    ++ans[u];
    return ++now;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    REP(i,2,n+1) {
        int p;
        cin >> p;
        g[p].PB(i);
    }
    REP(i,1,n+1)
        sort(ALL(g[i]));
    dfs(1);
    REP(i,1,n+1)
        cout << ans[i] << " \n"[i==n];
}
