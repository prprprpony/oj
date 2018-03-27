#include<bits/stdc++.h>
using namespace std;
const int N = 5566;
template<class T>
bool cmax(T & a, const T & b) {return a < b ? a = b, 1 : 0;}
int dp[N][N],a[N];
vector<tuple<int,int,int>> op;
void opt(int a,int b,int c) {if(a)op.emplace_back(a,b,c);}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,v;
    cin >> n >> k >> v;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        memcpy(dp[i],dp[i-1],sizeof(dp[i]));
        for (int j = 0; j < k; ++j) {
            int w = dp[i-1][j] + a[i];
            cmax(dp[i][w%k], w);
        }
    }
    int m = v % k;
    int s = dp[n][m];
    if (s % k != m) {
        cout << "NO\n";
        return 0;
    }
    if (s) {
        vector<int> ca;
        for (int i = n; i > 0; --i)
            if (dp[i][m] > dp[i-1][m]) {
                ca.push_back(i);
                m = ((m - a[i]) % k + k) % k;
            }
        int y = ca.back();
        for (int x : ca)
            if (x != y)
                opt((a[x] + k - 1) / k, x, y);
        if (s >= v) {
            int t = (s - v) / k;
            if (t)
                opt(t, y, 1==y?2:1);
            s = v;
        } else {
            int f = 0;
            for (int i = 1, j = ca.size() - 1; i <= n; ++i)
                if (j < 0 || i < ca[j]) {
                    if (!f) {
                        f = i;
                    } else {
                        opt((a[i]+k-1)/k,i,f);
                        a[f] += a[i];
                    }
                } else {
                    --j;
                }
            int r = min((v - s) / k, a[f] / k);
            if (r)
                opt(r, f, y);
            s += r * k;
        }
    } else {
        opt((a[1]+k-1)/k,1,2);
        a[2] += a[1];
        int f = 2;
        for (int i = 3; i <= n; ++i) {
            opt((a[i]+k-1)/k,i,f);
            a[f] += a[i];
        }
        int r = min((v - s) / k, a[f] / k);
        if (r)
            opt(r, f, 1);
        s += r * k;
    }
    if (s != v) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (const auto & x : op)
        cout << get<0>(x) << ' ' << get<1>(x) << ' ' << get<2>(x) << '\n';
}
