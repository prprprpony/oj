#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 897;
int n,m,l,p[N],ct;
ll h[N];
int find(int x) {return x == p[x] ? x : (p[x] = find(p[x]));}
void meld(int i,int j)
{
    p[find(i)] = find(j);
}
void upd(int i,int d)
{
    bool nw = h[i] <= l;
    h[i] += d;
    nw &= h[i] > l;
    if (nw) {
        ++ct;
        if (i + 1 < n && h[i+1] > l) {
            meld(i,i+1);
            --ct;
        }
        if (i-1 >= 0 && h[i-1] > l) {
            meld(i,i-1);
            --ct;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> l;
    iota(p,p+n,0);
    ct=0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        upd(i,x);
    }
    while (m--) {
        int t;
        cin >> t;
        if (!t)
            cout << ct << '\n';
        else {
            int i,d;
            cin >> i >> d;
            upd(i-1,d);
        }
    }
}
