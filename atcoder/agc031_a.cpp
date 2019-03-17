#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int cnt[26];
int main()
{
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i)
        cnt[s[i] - 'a']++;
    long long ans = 1;
    for (int i = 0; i < 26; ++i)
        ans = ans * (cnt[i] + 1) % M;
    cout << (ans+M-1)%M << endl;
}
