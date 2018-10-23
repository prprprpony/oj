#include<bits/stdc++.h>
using namespace std;
const int N = 2087;
char s[N][N];
int dp1[N][N], dp2[N*2][N], rk[N*2][N];
vector<pair<char,int>> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> (s[i] + 1);
        for (int j = 1; j <= n; ++j)
            dp1[i][j] = (s[i][j] == 'a') + max(dp1[i-1][j], dp1[i][j-1]);
    }
    memset(dp2,0x3f,sizeof(dp2));
    memset(rk,0x3f,sizeof(rk));
    int ak=-1,w;
    for (w = n*2; w >= 2; --w) {
        int il, ir;
        if (w > n + 1) {
            ir = n;
            il = w - n;
        } else {
            il = 1;
            ir = w - 1;
        }
        v.clear();
        for (int i = il; i <= ir; ++i) {
            int j = w - i;
            dp2[w][i] = min(rk[w+1][i], rk[w+1][i+1]);
            v.emplace_back(s[i][j],dp2[w][i]);
        }
        sort(begin(v),end(v));
        v.erase(unique(begin(v),end(v)),end(v));

        for (int i = il; i <= ir; ++i) {
            int j = w - i;
            rk[w][i] = lower_bound(begin(v),end(v),make_pair(s[i][j],dp2[w][i])) - begin(v);
            if (dp1[i][j] + k >= w - 1) {
                if (ak == -1 || dp2[w][i] < dp2[w][ak])
                    ak = i;
            }
//            cerr << endl << "wij" << w << ' ' << i << ' ' << j << endl; cerr << "s " << s[i][j] << " dp " << dp2[w][i] << " rk " << rk[w][i] << endl;
        }
        if (ak != -1) 
            break;
    }
 //   cerr << "wak " << w << ' ' << ak << endl;
    for (int i = 0; i < w-1; ++i)
        cout << 'a';
    int i;
    if (ak != -1) {
        i = ak + (rk[w+1][ak+1] == dp2[w][ak]);
    } else {
        i = 1;
    }
    ++w;
//    cerr << endl << "wi" << w << ' ' << i << endl;
    for (; w <= n * 2; ++w) {
        //cerr << endl << i << ' ' << w-i << endl;
        cout << s[i][w-i];
        if (rk[w+1][i+1] == dp2[w][i])
            ++i;
    }
    cout << '\n';
}
