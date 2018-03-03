#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 2e6 + 87, M = 1e9 + 7;
int mul(int a,int b) {return a * 1LL * b % M;}
int f[N],fi[N];
void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i) f[i] = mul(i, f[i-1]);
    fi[0] = fi[1] = 1;
    for (int i = 2; i < N; ++i) fi[i] = mul(M-M/i,fi[M%i]);
    for (int i = 2; i < N; ++i) fi[i] = mul(fi[i],fi[i-1]);
}
int main()
{
    pre();
    int n,k;
    cin >> n >> k;
    ll tot=0;
    for (int b = 1; 2 * b < n; ++b) {
        int ib = fi[b], c = n-b;
        for (int a = 2; a <= k - 1 && (c -= b) > 0; ++a) {
            ib = mul(ib, fi[b]);
            if (b != c)
                tot += mul(mul(ib,mul(fi[a],fi[k-a-1])),fi[c]);
        }
    }
    cout << mul(mul(tot%M,f[n]),f[k]) << endl;
}
