#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1e5 + 66;
int gcd(int a,int b) {return b ? gcd(b,a%b) : abs(a);}
pii vec(pii a,pii b)
{
    int x = a.F - b.F, y = a.S - b.S;
    int g = gcd(x,y);
    x /= g, y /= g;
    if (x < 0)
        x *= -1, y *= -1;
    else if (x == 0)
        y = 1;
    return pii(x,y);
}
pii a[N];
map<pii,int> m;
pii vec(int i,int j)
{
    return vec(a[i],a[j]);
}
int chk(const vector<pii> & v)
{
    if (v.size() < 3)
        return 0;
    int c = 0;
    pii p = vec(v[0],v[1]);
    for (int i = 1; i < v.size(); ++i)
        if (vec(v[i],v[0]) != p)
            ++c;
    return c; 
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n <= 4) {
        cout << "YES\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i].F >> a[i].S;
        if (i) 
            ++m[vec(0,i)];
    }
    if (m.size() <= 2) {
        cout << "YES\n";
        return 0;
    }
    int c = 0;
    pii p(0,0);
    for (auto it = begin(m); it != end(m); ++it)
        if (it->S > 1) {
            p = it->F;
            c++;
        }
    if (c > 1) {
        cout << "NO\n";
        return 0;
    }
    bool ok = 0;
    vector<pii> v;       
    if (c == 1) {
        for (int i = 1; i < n; ++i)
            if (vec(i,0) != p)
                v.push_back(a[i]);
        ok = !chk(v);
    } else {
        for (int i = 1; i < n; ++i)
            v.push_back(a[i]);
        ok |= chk(v) <= 1;
        swap(v[1],v[2]);
        ok |= chk(v) <= 1;
        swap(v[0],v[2]);
        ok |= chk(v) <= 1;
    }
    cout << (ok ? "YES\n" : "NO\n");
}
