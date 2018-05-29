#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second
template<class T>
bool cmax(T & a,const T & b) {return a < b ? a = b, 1 : 0;}
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define PER(i,a,b) for (int i((a)-1); i >= (b); --i)
#define SZ(a) ((int)(a).size())
/*>_<*/
const int N = 1e4 + 87, M = 1010102101, P = 52127;
ll pw[N];
int a[N];
char s[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    pw[0] = 1;
    REP(i,1,N) pw[i] = pw[i-1] * P % M;
    int q;
    cin >> q >> (s + 1);
    int n = 0, ans = 0;
    REP(i,1,q+1) {
        if (s[i] != '-') {
            s[++n] = s[i] - 'a';
            a[n] = 0;
            ll rh = 0, hs = 0;
            PER(j,n+1,1) {
                hs = (hs + pw[n-j] * s[j]) % M;
                rh = (rh * P + s[j]) % M;
                a[n] += hs == rh;
            }
            ans += a[n];
        } else {
            ans -= a[n--];
        }
        cout << ans << " \n"[i==q];
    }
}
