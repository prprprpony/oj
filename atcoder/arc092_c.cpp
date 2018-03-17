#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1087;
pair<ll,int> solve(ll x[],int n)
{
    ll s = 0, mx = LLONG_MIN;
    int c = 0;
    for (int i = 0; i < n; ++i) 
        if (x[i] >= 0)
            s += x[i], ++c;
        else
            mx = max(mx, x[i]);
    return c ? pair<ll,int>(s,c) : pair<ll,int>(mx, 1);
}
vector<int> op;
ll a[2][N];
void go(int x) {op.push_back(x);}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i&1][i>>1];
    pair<ll,int> p[2] = {solve(a[0],n/2+n%2), solve(a[1],n/2)};
    int k = p[0] < p[1] ? 1 : 0;
    cout << p[k].F << '\n';
    if (p[k].F < 0) {
        for (; a[(n-1)%2][(n-1)/2] < p[k].F; --n)
            go(n);
        for (int i = 0; i < n - 1; ++i)
            go(1);
    } else {
        for (--n; n > k; ) { 
            if (n%2 != k || a[n%2][n/2] < 0) {
                go(n+1);
                --n;
            } else {
                if (a[k][n/2-1] < 0) {
                    if (n-3 >= 0)
                        go(n+1-2);
                    else
                        go(1),go(1),n=0;
                    a[k][n/2-1] = a[k][n/2];
                } else {
                    go(n-1+1);
                }
                n-=2;
            }
        }
        if (k)
            go(1);
    }
    cout << op.size() << '\n';
    for (int x : op)
        cout << x << '\n';
}
