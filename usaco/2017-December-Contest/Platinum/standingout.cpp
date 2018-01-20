#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define PER(i,a,b) for (int i((a)-1); i >= (b); --i)
typedef pair<int,int> pii;
#define F first
#define S second
const int N = (1e5 + 87) * 2;
int sa[N],rk[N],ht[N];
void make_sa(int * s,int n,int m)
{
    static int cnt[N], buf[2][N];
    int * r = buf[0], * b = buf[1];
    memset(cnt,0,m*sizeof(cnt[0]));
    REP(i,0,n) ++cnt[s[i]];
    REP(i,1,m) cnt[i] += cnt[i-1];
    PER(i,n,0) sa[--cnt[s[i]]] = i;
    r[sa[0]] = 0;
    REP(i,1,n) r[sa[i]] = r[sa[i-1]] + (s[sa[i]] != s[sa[i-1]]);
    for (int k = 1; k < n && (m = r[sa[n-1]] + 1) < n; k <<= 1) {
        int tp = 0;
        REP(i,n-k,n) b[tp++] = i;
        REP(i,0,n) if (sa[i] - k >= 0) b[tp++] = sa[i] - k;
        memset(cnt,0,m*sizeof(cnt[0]));
        REP(i,0,n) ++cnt[r[b[i]]];
        REP(i,1,m) cnt[i] += cnt[i-1];
        PER(i,n,0) sa[--cnt[r[b[i]]]] = b[i];
        swap(b,r);
        r[sa[0]] = 0;
        REP(i,1,n) r[sa[i]] = r[sa[i-1]] + !(b[sa[i-1]] == b[sa[i]] && b[sa[i-1]+k] == b[sa[i] + k]);
    }
    memcpy(rk,r,n*sizeof(r[0]));
    int h = ht[0] = 0;
    REP(i,0,n) {
        if (!rk[i]) {h = 0;continue;}
        if (h) --h;
        for (;s[i+h] == s[sa[rk[i]-1]+h]; ++h);
        ht[rk[i]] = h;
    }
}
void pt(const char * msg,int * a,int l,int r)
{
    fputs(msg,stdout);
    for (; l < r; ++l)
        printf("%d ",a[l]);
    puts("");
}
int t[N],len[N],idx[N],po[N];
int main()
{
    FILE * in = fopen("standingout.in","r");
    FILE * out = fopen("standingout.out","w");
    int n;
    fscanf(in,"%d ",&n);
    REP(i,1,n+1) {
        len[i] = len[i-1];
        int c;
        while (isalpha(c = getc(in)))
            t[len[i]++] = c - 'a';
        t[len[i]++] = i + 25;
        fill(idx+len[i-1],idx+len[i],i);
    }
    int m = len[n];
    make_sa(t,m,n+26);
    PER(i,m-1,0) {
        int x = sa[i], y = sa[i+1];
        if (idx[x] != idx[y])
            po[x] = ht[i+1];
        else
            po[x] = min(po[y], ht[i+1]);
    }
    REP(i,1,n+1) {
        long long ans = 0;
        int w = len[i]-1;
        REP(j,len[i-1],w)
            ans += w - j - max(ht[rk[j]],po[j]);
        fprintf(out,"%lld\n",ans);
    }
}
