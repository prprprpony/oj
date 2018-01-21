#include<bits/stdc++.h>
using namespace std;
#define ALL(a) begin(a), end(a)
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define RP(i,n) REP(i,0,n)
template<class T>
bool cmin(T&a,const T&b) {return b < a ? a = b, 1 : 0;}
const int N = 56, inf = 0x3f3f3f3f;
int ans[N][N];
int n,m,k;
bool ck(int r,int c,int & v)
{
    ++v;
    if (1 <= r and r <= n and 1 <= c and c <= m) {
        cmin(ans[r][c], v);
        return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> k;
    memset(ans, 0x3f, sizeof(ans));
    while (k--) {
        int r, c, t, v = 1;
        cin >> r >> c >> t;
        cmin(ans[r][c],1);
        if (t) {
            for (int w = 1, ok = 1; ok; ++w) {
                ok = ck(--r,c,v);
                RP(i,w*2-1) 
                    ok |= ck(r,--c,v);
                RP(i,w*2)
                    ok |= ck(++r,c,v);
                RP(i,w*2)
                    ok |= ck(r,++c,v);
                RP(i,w*2)
                    ok |= ck(--r,c,v);
            }
        } else {
            for (int w = 1, ok = 1; ok; ++w) {
                ok = ck(--r,c,v);
                RP(i,w*2-1) 
                    ok |= ck(r,++c,v);
                RP(i,w*2)
                    ok |= ck(++r,c,v);
                RP(i,w*2)
                    ok |= ck(r,--c,v);
                RP(i,w*2)
                    ok |= ck(--r,c,v);
            }
        }
    }
    REP(i,1,n+1)
        REP(j,1,m+1)
            cout << ans[i][j] << " \n"[j == m];
}
