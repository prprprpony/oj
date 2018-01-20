#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i(a);i<(b);++i)
#define RP(i,n) REP(i,0,n)
typedef pair<int,int> pii;
#define F first
#define S second
template<class T,class U> pair<T,U> operator + (const pair<T,U> & a,const pair<T,U> & b) {return {a.F+b.F,a.S+b.S};}
#define PB push_back
#define SZ(a) ((int)(a).size())
#define ALL(a) begin(a),end(a)
template<class T> bool cmin(T&a,const T&b){return b<a?a=b,1:0;}
const int N = 1507;
const int M = N * N;
const pii dt[] = {{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
char s[N][N];
bitset<M> vis;
vector<int> g[M], bid[M], bcc[M];
int tin[M], dfn, st[M], tp, nb, ans[N][N];
int idx(int i,int j) {return i * m + j;}
int idx(pii x) {return idx(x.F,x.S);}
bool ok(int x,int y) {return 0 <= x and x < n and 0 <= y and y < m and s[x][y] != '#';}
void add(int u,int v) {g[u].PB(v);g[v].PB(u);}
int dfs(int p,int u)
{
    int low = tin[u] = ++dfn, c = 0;
    st[tp++] = u;
    for (int v : g[u]) 
        if (!tin[v]) {
            ++c;
            int x = dfs(u,v);
            cmin(low,x);
            if (x >= tin[u]) {
                int t;
                do {
                    bid[t = st[--tp]].PB(nb);
                    bcc[nb].PB(t);
                } while (t != v);
                bid[u].PB(nb);
                bcc[nb].PB(u);
                sort(ALL(bcc[nb]));
                ++nb;
            }
        } else if (v != p) {
            cmin(low,tin[v]);
        }
    return low;
}
bool cnc(pii a,pii x)
{
    int u = idx(a), v = idx(x);
    for (int i : bid[u])
        if (binary_search(ALL(bcc[i]),v))
            return 1;
    return 0;
}
int main()
{
    freopen("pushabox.in","r",stdin);
    freopen("pushabox.out","w",stdout);
    int qn;
    scanf("%d%d%d",&n,&m,&qn);
    pii a,b;
    RP(i,n) {
        scanf("%s",s[i]);
        RP(j,m) {
            if (s[i][j] == '#')
                continue;
            if (s[i][j] == 'A')
                a = {i,j};
            if (s[i][j] == 'B')
                b = {i,j};
            if (i and s[i-1][j] != '#')
                add(idx(i,j),idx(i-1,j));
            if (j and s[i][j-1] != '#')
                add(idx(i,j),idx(i,j-1));
        }
    }
    dfs(-1,idx(a.F,a.S));
    queue<pii> qq;
    qq.push(a);
    vis[idx(a)] = 1;
    queue<pair<pii,pii>> q;
    while (SZ(qq)) {
        a = qq.front();
        qq.pop();
        RP(i,4) {
            pii t = a + dt[i];
            if (ok(t.F,t.S) and t != b and !vis[idx(t)]) {
                vis[idx(t)] = 1;
                qq.push(t);
            }
            if (t == b)
                q.push({a,b});
        }
    }
    pii b0 = b;
    while (SZ(q)) {
        tie(a,b) = q.front();
        q.pop();
        RP(i,4) {
            pii y = b + dt[i], x = b + dt[i^1];
            if (ok(x.F,x.S) and ok(y.F,y.S) and cnc(a,x) and !(ans[y.F][y.S]>>i&1)) {
                ans[y.F][y.S] |= 1<<i;
                q.push({b,y});
            }
        }
    }
    ans[b0.F][b0.S] = 1;
    while (qn--) {
        int i,j;
        scanf("%d%d",&i,&j);
        --i,--j;
        puts(ans[i][j] ? "YES" : "NO");
    }
}
