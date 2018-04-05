#include<bits/stdc++.h>
using namespace std;
#define ALL(a) begin(a),end(a)
template<class T>
bool cmin(T & a,const T & b) {return b < a ? a = b, 1 : 0;}
const int N = 5e5 + 87;
void make_fail(const string & s,int f[])
{
    f[0] = f[1] = 0;
    for (int i = 1, j = 0; i < s.size(); ++i) {
        while (s[i] != s[j] && j)
            j = f[j];
        j += s[i] == s[j];
        f[i+1] = j;
    }
}
void calc(const string & s,const string & t,int k,int p[], bool ck = 0)
{
    static int f[N];
    make_fail(t,f);
    fill_n(p,t.size()+1,s.size());
    for (int i = 0, j = 0; i < s.size(); ++i) {
        while (s[i] != t[j] && j)
            j = f[j];
        j += s[i] == t[j];
        if (i + 1 >= k)
            cmin(p[j], i);
        if (j == t.size()) {
            if (ck && j <= k) {
                int l, r;
                l = r = -1;
                if (s.size() - 1 - i >= k) {
                    r = s.size() - k;
                    if (i <= k - 1)
                        l = 0;
                    else
                        l = i - (k - 1);
                } else if (i - (j-1) >= k) {
                    l = 0;
                    r = k+k-1 >= i  ? k : i - (k-1);
                }
                if (l >= 0) {
                    cout << "Yes\n" << l + 1 << ' ' << r + 1 << '\n';
                    exit(0);
                }
            }
            j = f[j];
        }
    }
    for (int i = t.size(); i >= 0; --i)
        cmin(p[f[i]], p[i]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k,p[N],q[N];
    string s,t;
    cin >> n >> m >> k >> s >> t;
    calc(s,t,k,p,1);
    reverse(ALL(s));
    reverse(ALL(t));
    calc(s,t,k,q);
    for (int i = max(0,m - k); i <= k && i <= m; ++i) {
        int l = p[i], r = n-1-q[m-i];
        if (l < r) {
            cout << "Yes\n" << l - (k - 1) + 1 << ' ' << r + 1 << '\n';
            return 0;
        }
    }
    cout << "No\n";
}
