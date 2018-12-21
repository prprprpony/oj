#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    long long ans=0,w=0;
    for (int i = s.size()-1; i >= 0; --i)
        if (s[i] == 'W')
            ++w;
        else
            ans += w;
    cout << ans << endl;
}
