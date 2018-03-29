#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    int ans = n;
    for (int i = 1; i <= n/2; ++i)
        if (s.substr(0,i) == s.substr(i,i))
            ans = n - i + 1;
    cout << ans << endl;
}
