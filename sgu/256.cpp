#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
const int B = 5, N = 3125 * 101;
typedef unsigned char byte;
typedef pair<byte,byte> pii;
byte q[N][B+1];
short dis[N];
unsigned encode(byte a[])
{
    unsigned x = 0;
    for (int i = B; i >= 1; --i)
        x = x * B + a[i];
    return x * 100 + a[0];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,n;
    cin >> m >> n;
    vector<pii> v;
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin >> a >> b;
        v.emplace_back(a,b);
    }
    if (n > B) {
        nth_element(begin(v),begin(v)+B,end(v),greater<pii>());
        v.resize(B);
    }
    v.resize(B,pii(0,0));
    dis[encode(q[0])] = 1;
    for (int ql=0,qr=1; ql < qr; ++ql) {
        auto a = q[ql];
        auto d = dis[encode(a)] + 1;
        for (int i = 1; i <= B; ++i)
            if (a[i] == 0) {
                auto b = q[qr];
                memcpy(b,a,sizeof q[0]);
                if ((b[0] += v[i-1].F) >= m) {
                    cout << d - 1 << endl;
                    return 0;
                }
                for (int j = 1; j <= B; ++j)
                    if (b[j])
                        --b[j];
                b[i] = v[i-1].S;
                auto & w = dis[encode(b)];
                if (!w) {
                    w = d;
                    ++qr;
                }
            }
        auto b = q[qr];
        memcpy(b,a,sizeof q[0]);
        for (int j = 1; j <= B; ++j)
            if (b[j])
                --b[j];
        auto & w = dis[encode(b)];
        if (!w) {
            w = d;
            ++qr;
        }
    }
}
