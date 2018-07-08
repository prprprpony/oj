#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 106, M = 1e8;
const double pi = acos(-1);
pii a[N], b[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        double t = 2 * pi * i / n;
        a[i] = pii(M * cos(t), M * sin(t));
        assert(abs(a[i].F) <= M and abs(a[i].S) <= M);
        cout << a[i].F << ' ' << a[i].S << '\n';
    }
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        b[i].F = (3 * a[i].F + a[j].F) / 4;
        b[i].S = (3 * a[i].S + a[j].S) / 4;
        assert(abs(b[i].F) <= M and abs(b[i].S) <= M);
        cout << b[i].F << ' ' << b[i].S << '\n';
    }
}
