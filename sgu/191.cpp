#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    string s; 
    cin >> c >> s;
    int n = s.size(), i;
    vector<int> st{c-'A'};
    for (i = 0; i < n; ++i) {
        if (!st.size())
            break;
        int o = st.back();
        st.pop_back();
        if (s[i]-'A' == o) {
            st.push_back(o);
            st.push_back(o^1);
        }
    }
    cout << (i == n && st.empty() ? "YES\n" : "NO\n");
}
