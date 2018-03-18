#include<bits/stdc++.h>
using namespace std;
const int W = 29, N = 2e5 + 87;
int mem[3][N], k, n;
void ct_sort(int *& a, int *& v)
{
    int c[2] = {};
    for (int i = 0; i < n; ++i)
        ++c[a[i]>>k&1];
    c[1] += c[0];
    for (int i = n - 1; i >= 0; --i)
        v[--c[a[i]>>k&1]] = a[i];
    swap(a, v);
}
int * a = mem[0], * b = mem[1], * v = mem[2];
int g(int x) {return x & ((1 << (k + 1)) - 1);}
int cal(int vl,int vr)
{
    int l=n,r=n,c=0;
    for (int i = 0; i < n; ++i) {
        while (l - 1 >= 0 && g(a[l-1]) >= vl - g(b[i]))
            --l;
        while (r - 1 >= 0 && g(a[r-1]) >= vr - g(b[i]))
            --r;
        c = (r - l + c) & 1;
    }
    return c;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    int ans = 0;
    for (k = 0; k < W; ++k) {
        ct_sort(a,v);
        ct_sort(b,v);
        ans |= (cal(1<<k,2<<k) ^ cal(3<<k,4<<k)) << k;
    }
    cout << ans << endl;
}
