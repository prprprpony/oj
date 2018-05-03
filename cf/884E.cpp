#include<bits/stdc++.h>
using namespace std;
const int N = 1<<12, M = 1<<14;
const int W = M * 2;
bitset<M> s[2];
int p[W + 1];
int find(int x) {return x == p[x] ? x : p[x] = find(p[x]);}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int ans=0,b=0,l=0,r=m;
    p[W] = W;
    for (int i = 0; i < n; ++i, b^=1, swap(l,r)) {
        for (int j = 0; j < m/4; j++) {
            char c;
            cin >> c;
            int x = isdigit(c) ? c - '0' : c - 'A' + 10;
            for (int k = 0; k < 4; ++k, x>>=1)
                s[b][j*4+3-k] = x&1;
        }
        /*
auto t(s[b].to_string().substr(M-m));
reverse(begin(t),end(t));
cout << t << endl;
*/
        iota(p+l,p+l+m,l);
        /*
cerr << "l,r " << l << ',' << r << endl;
for (int j = 0; j < m * 2; ++j)
    cerr << p[j] << endl;
cerr << "=========" << endl;
*/
        for (int j = 0; j < m; ++j)
            if (s[b][j]) {
                if (j && s[b][j-1])
                    p[find(l + j)] = find(l + j - 1);
                if (i && s[b^1][j])
                    p[find(r + j)] = find(l + j);
            }
        if (i) {
            /*
for (int j = 0; j < m * 2; ++j)
    cerr << p[j] << endl;
return 0;
*/
            for (int j = 0; j < m; ++j)
                if (s[b^1][j]) {
                    int x = find(r + j);
                    if (r <= x && x < r + m) {
                        ++ans;
                        p[x] = W;
                    }
                }
        }
    }

    for (int j = 0; j < m; ++j)
        if (s[b^1][j]) {
            int x = find(r + j);
            if (r <= x && x < r + m) {
                ++ans;
                p[x] = W;
            }
        }
    cout << ans << '\n';
}
