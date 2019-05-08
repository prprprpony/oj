#include<bits/stdc++.h>
using namespace std;
int c[26];
int main()
{
    string s;
    cin >> s;
    for (char x : s)
        c[x-'a']++;
    long long ans = 1;
    for (int i = 0; i < 26; ++i)
        for (int j = i + 1; j < 26; ++j)
            ans += c[i] * 1LL * c[j];
    cout << ans << endl;
}
