#include<bits/stdc++.h>
using namespace std;
const int N = 1087;
map<string,int> mp;
vector<int> g[N];
int a[N],ct[N];
int id(const string & s)
{
    if (!mp.count(s)) {
        int t = mp.size() + 1;
        mp[s] = t;
    }
    return mp[s];
}
int dfs(int u)
{
    int ans = 0, oct = ct[a[u]];
    for (int v : g[u])
        ans += dfs(v);
    ans += ct[a[u]] - oct;
    ct[a[u]]++;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    string s,t;
    cin >> s;
    vector<int> st{0};
    int n = 0;
    for (int i = 0; s[i]; ++i) {
        if (isalpha(s[i])) {
            t += s[i];
        } else {
            switch (s[i]) {
            case ':':
                ++n;
                a[n] = id(t);
                t.clear();
                g[st.back()].push_back(n);
                st.push_back(n);
                break;
            case '.':
                if (isalpha(s[i-1])) {
                    ++n;
                    a[n] = id(t);
                    t.clear();
                    g[st.back()].push_back(n);
                    st.push_back(n);
                }
                st.pop_back();
                break;
            default:
                break;
            }
        } 
    }
    cout << dfs(1) << endl;
}
