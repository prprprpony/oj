#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i(a),_B(b);i<_B;++i)
#define PER(i,a,b) for (int i((a)-1),_B(b);i>=_B;--i)
typedef pair<int,int> pii;
typedef vector<int> vi;
#define F first
#define S second
#define EB emplace_back
#define PB push_back
#define SZ(a) ((int)a.size())
const int N = 1e5+87;
char s[N];
vector<pii> p[3];
int main()
{
    scanf("%s",s);
    int n = strlen(s), v =  0;
    REP(i,0,n) {
        s[i] -= '0';
        v+=s[i];
        v%=3;
    }
    int m = 0;
    PER(i,n,0) {
        if (s[i]%3)
            p[s[i]%3].EB(i,m+1==n?m:m+1);
        m = s[i] ? 0 : m + 1;
    }
    REP(k,1,3)
        for (int i =0,j=SZ(p[k])-1;i<j;++i,--j)
            swap(p[k][i],p[k][j]);
    if (!v) {
        REP(i,0,n) putchar(s[i]+'0');
        puts("");
    } else if (v == 1) {
        vi pos,tmp;
        if (SZ(p[1])) {
            if (p[1].back().F)
                tmp.EB(p[1].back().F);
            else {
                REP(i,0,p[1][0].S)
                    tmp.EB(i);
            }
        }
        if (SZ(tmp))
            pos.swap(tmp);
        if ((!SZ(pos) || SZ(pos) > 2) && SZ(p[2])>=2) {
            int t=SZ(p[2]);
            pii x = p[2][t-2], y=p[2][t-1];
            if (x.F) {
                tmp = {x.F,y.F};
            } else if (y.F==x.S) {
                REP(i,0,y.F+y.S)
                    tmp.EB(i);
            } else {
                REP(i,0,x.S)
                    tmp.EB(i);
                tmp.EB(y.F);
            }
            if (!SZ(pos) || (SZ(tmp) && SZ(tmp) < SZ(pos)))
                pos.swap(tmp);
        }
        if (!SZ(pos)) {
            puts("-1");
        } else {
            for (int i : pos) s[i] = -1;
            int c=0;
            REP(i,0,n) if (s[i]>=0) {
                putchar(s[i]+'0');
                ++c;
            }
            if (c)
                puts("");
            else if (n>2)
                puts("0");
            else
                puts("-1");
        }
    } else {
        vi pos,tmp;
        if (SZ(p[2])) {
            if (p[2].back().F)
                tmp.EB(p[2].back().F);
            else {
                REP(i,0,p[2][0].S)
                    tmp.EB(i);
            }
        }
        if (SZ(tmp))
            pos.swap(tmp);
        if ((!SZ(pos) || SZ(pos) > 2) && SZ(p[1])>=2) {
            int t=SZ(p[1]);
            pii x = p[1][t-2], y=p[1][t-1];
            if (x.F) {
                tmp = {x.F,y.F};
            } else if (y.F==x.S) {
                REP(i,0,y.F+y.S)
                    tmp.EB(i);
            } else {
                REP(i,0,x.S)
                    tmp.EB(i);
                tmp.EB(y.F);
            }
            if (!SZ(pos) || (SZ(tmp) && SZ(tmp) < SZ(pos)))
                pos.swap(tmp);
        }
        if (!SZ(pos)) {
            puts("-1");
        } else {
            for (int i : pos) s[i] = -1;
            int c=0;
            REP(i,0,n) if (s[i]>=0) {
                putchar(s[i]+'0');
                ++c;
            }
            if (c)
                puts("");
            else if (n>2)
                puts("0");
            else
                puts("-1");
        }
    }
}
