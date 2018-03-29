#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    int ans = s.size(), f = 0;
    for (int i = 1; i < s.size(); ++i) {
        --f;
        if (s[i] != s[i-1] && f < 0) {
            ans--;
            f=1;
        }
    }
    cout << ans << endl;
}
