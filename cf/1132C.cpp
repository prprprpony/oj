#include<bits/stdc++.h>
using namespace std;
const int N = 5056;
int n,q;
int l[N],r[N],s[N],s1[N],s2[N];
int main()
{
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        cin >> l[i] >> r[i];
        ++s[l[i]];
        --s[r[i]+1];
    }
    int tot = 0;
    for (int i = 1; i <= n; ++i) {
        s[i] += s[i-1];
        tot += s[i] > 0;
        if (s[i] == 1)
            ++s1[i];
        else if (s[i] == 2)
            ++s2[i];
        s1[i] += s1[i-1];
        s2[i] += s2[i-1];
    }
    int ans = 0;
    for (int i = 0; i < q; ++i)
        for (int j = i + 1; j < q; ++j) {
            int c = s1[r[i]]-s1[l[i]-1]+s1[r[j]]-s1[l[j]-1];
            int x = max(l[i],l[j]);
            int y = min(r[i],r[j]);
            if (x <= y)
                c += s2[y] - s2[x-1];
            ans = max(ans, tot - c);
        }
    cout << ans << endl;
}
