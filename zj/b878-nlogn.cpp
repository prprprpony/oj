#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e6 + 87;
pair<int,int> m[N];
int f[N];
void add(int i)
{
    for (; i < N; i += i & -i)
        ++f[i];
}
int qry(int i)
{
    int ans = 0;
    for (; i; i ^= i & -i)
        ans += f[i];
    return ans;
}
int bs(int v)
{
    int i = 0;
    for (int k = 1<<__lg(N); k; k >>= 1)
        if ((i | k) < N && f[i | k] < v)
            v -= f[i |= k];
    return i + 1;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m[i].first;
        m[i].second = i;
    }
    sort(m,m+n);
// -1 -> 1
// i  -> i + 2
    add(1), add(n+2);
    long long ans = 0;
    for (int p = 0; p < n; ++p) {
        const int & i = m[p].second + 2;
        int r = qry(i);
        ans += min(i - bs(r), bs(r+1) - i);
        add(i);
    }
    printf("%lld\n",ans);
}
