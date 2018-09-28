#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 87;
char s[N];
deque<int> p[26];
int f[N];
void add(int i,int v)
{
    for (; i < N; i += i & -i)
        f[i] += v;
}
int qry(int i)
{
    int r = 0;
    for (; i; i ^= i & - i)
        r += f[i];
    return r;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> (s+1);
    int n = strlen(s+1);
    for (int i = 1; i <= n; ++i) {
        p[s[i]-'a'].push_back(i);
        add(i,1);
    }
    int mi = -1;
    for (int i = 0; i < 26; ++i)
        if (p[i].size() & 1) {
            if (mi != -1 || n % 2 == 0) {
                cout << "-1\n";
                return 0;
            }
            mi = i;
        }
    long long ans = 0;
    for (int i = 0, l = 1; i < n/2; ++i, ++l) {
        while (p[s[l]-'a'].size() < 2)
            ++l;
        auto & q = p[s[l]-'a'];
        ans += qry(l-1) + n - 2 * i - qry(q.back());
        add(l,-1);
        add(q.back(),-1);
        q.pop_front();
        q.pop_back();
    }
    cout << ans << '\n';
}
