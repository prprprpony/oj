#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ALL(a) begin(a), end(a)
#define SZ(a) ((int)(a).size())
/*>_<*/
vector<string> v[26];
int idx[26];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v[s[0] - 'a'].PB(s);
    }
    for (int i = 0; i < 26; ++i)
        sort(ALL(v[i]));
    while (m--) {
        char c;
        cin >> c;
        c -= 'a';
        int & i = idx[c];
        cout << v[c][i++] << '\n';
        if (i == SZ(v[c]))
            i = 0;
    }
}
