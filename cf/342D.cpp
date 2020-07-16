#include <bits/stdc++.h>
using namespace std;
/* nichijou */
template<class T,class U>
bool cmax(T & a, const U & b) {return a < b ? a = b, 1 : 0;}
template<class T,class U>
bool cmin(T & a, const U & b) {return b < a ? a = b, 1 : 0;}
/* data type */
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define F first
#define S second
/* STL container */
typedef vector<int> vi;
typedef vector<ll> vll;
#define SZ(a) ((int)(a).size())
#define ALL(a) begin(a), end(a)
#define CLR(a) (a).clear()
#define BK(a) ((a).back())
#define FT(a) ((a).front())
#define DB(a) (a).pop_back()
#define DF(a) (a).pop_front()
#define PB push_back
#define EB emplace_back
/* I gave you my heart and then you turned around. */
void _BG(const char * s) {cerr<<s<<endl;}
template<class T, class ... TT>
void _BG(const char * s,T a, TT...b)
{
    for (size_t c = 0; *s && (c || *s != ','); cerr << *s++)
        c += count(ALL("([{"),*s) - count(ALL(")]}"),*s);
    cerr << " = " << a;
    if (*s) {
        cerr << ", ";
        ++s;
    }
    _BG(s,b...);
}
#ifdef PR3PONY
#define BG(...) do { \
    cerr << __PRETTY_FUNCTION__ << ':' << __LINE__ << ": "; \
    _BG(#__VA_ARGS__,__VA_ARGS__); \
} while(0)
#else
#define BG(...)
#endif
/* Good Luck && Have Fun ! */
const int MOD = 1e9 + 7;
const int N = 1e4 + 87;
int n;
char s[3][N];
bool p[5][3][5];
char tmp[3][5];
ll dp[N][1 << 3];
int getm(int j)
{
    int ret = 0;
    for (int i = 0; i < 3; ++i)
        ret += (s[i][j] == 'X') << i;
    return ret;
}
ll cal()
{
    memset(dp, 0, sizeof dp);
    dp[0][getm(0)] = 1;
    for (int j = 0; j < n; ++j) {
        for (int S = 0; S < 8; ++S) {
            if (S == 0) {
                (dp[j][3] += dp[j][0]) %= MOD;
                (dp[j][6] += dp[j][0]) %= MOD;
            } else if (S == 1) {
                (dp[j][7] += dp[j][1]) %= MOD;
            } else if (S == 4) {
                (dp[j][7] += dp[j][4]) %= MOD;
            }
            int nx = getm(j + 1);
            int rs = 7 ^ S;
            if (rs & nx)
                continue;
            (dp[j + 1][rs | nx] += dp[j][S]) %= MOD;
        }
    }
    BG(dp[n-1][7]);
    return dp[n - 1][7];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int j = 0; j < 5; ++j)
        p[0][1][j] = 1;

    for (int j = 0; j < 4; ++j)
        p[1][1][j] = 1;
    p[1][2][3] = 1;

    for (int j = 0; j < 4; ++j)
        p[2][1][j] = 1;
    p[2][0][3] = 1;


    for (int j = 1; j < 5; ++j)
        p[3][1][j] = 1;
    p[3][2][1] = 1;

    for (int j = 1; j < 5; ++j)
        p[4][1][j] = 1;
    p[4][0][1] = 1;

    cin >> n >> s[0] >> s[1] >> s[2];
    ll ans = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < n; ++j)
            if (s[i][j] == 'O') {
                if (i == 1) {
                    if (j != 0 && j != n - 1) {
                        for (int x = 0; x < 5; ++x) {
                            bool ok = 1;
                            for (int a = 0; a < 3; ++a)
                                for (int b = 0; b < 5; ++b)
                                    if (p[x][a][b]) {
                                        if (j + b - 2 >= 0 && j + b - 2 < n) {
                                            tmp[a][b] = s[a][j + b - 2];
                                            if (s[a][j + b - 2] != 'X') {
                                                s[a][j + b - 2] = 'X';
                                            } else {
                                                BG(x,a,b,"==X");
                                                ok = 0;
                                            }
                                        } else {
                                            BG(x,a,b,"out of bound");
                                            ok = 0;
                                        }
                                    }
                            BG(i,j,x,ok);
                            if (ok)
                                ans += cal();
                            for (int a = 0; a < 3; ++a)
                                for (int b = 0; b < 5; ++b)
                                    if (p[x][a][b] && j + b - 2 >= 0 && j + b - 2 < n) {
                                        s[a][j + b - 2] = tmp[a][b];
                                    }
                        }
                    } else if (j == 0) {
                        if (s[1][1] == '.' && s[1][2] == '.') {
                            s[1][0] = s[1][1] = s[1][2] = 'X';
                            ans = cal();
                        }
                    } else if (j == n - 1) {
                        if (s[1][n - 2] == '.' && s[1][n - 3] == '.') {
                            s[1][n - 1] = s[1][n - 2] = s[1][n - 3] = 'X';
                            ans = cal();
                        }
                    }
                } else {
                    s[i][j] = 'X';
                    ans += cal();
                }
            }
    cout << (ans % MOD + MOD) % MOD << endl;
}
