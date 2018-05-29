#include<bits/stdc++.h>
using namespace std;
template<class T>
bool cmax(T & a,const T & b) {return a < b ? a = b, 1 : 0;}
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define PER(i,a,b) for (int i((a)-1); i >= (b); --i)
//
const int N = 1e6 + 87;
char s[N];
int sa[N],ct[N],w[2][N];
void bld(int n,int m = 256)
{
    memset(ct,0,m*sizeof(int));
    int *x = w[0], *y=w[1];
    REP(i,0,n) ++ct[x[i] = (unsigned char)s[i]];
    REP(i,1,m) ct[i] += ct[i-1];
    PER(i,n,0) sa[--ct[x[i]]] = i;
    for (int j = 1, p = 1; p < n; j <<= 1, m = p) {
        p = 0;
        REP(i,n-j,n) y[p++] = i;
        REP(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
        memset(ct,0,m*sizeof(int));
        REP(i,0,n) ++ct[x[y[i]]];
        REP(i,1,m) ct[i] += ct[i-1];
        PER(i,n,0) sa[--ct[x[y[i]]]] = y[i];
        swap(x,y);
        x[sa[0]] = 0;
        p = 1;
        REP(i,1,n)
            x[sa[i]] = y[sa[i]] == y[sa[i-1]]
                       && y[sa[i] + j] == y[sa[i-1] + j] ? p-1 : p++;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n >> s;
    bld(n+1);
    int k = 0;
    while (k < n && s[k] == '1')
        ++k;
//    cerr << "k=" << k << endl;
    if (k == n) {
        cout << "0 0" << endl;
        return 0;
    }
    /*
    REP(i,0,n+1) {
        cerr << "sa[" << i << "]=" << sa[i] << endl;
        cerr << s + sa[i] << endl;
    }
    */
    PER(i,n+1,1)
        if (sa[i] >= k) {
            cout << k << ' ' << sa[i] - k << endl;
            return 0;
        }
}
