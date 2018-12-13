#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    map<int,int> mp;
    long long s = 0;
    ++mp[0];
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        mp[a]++;
        s += a;
    }
    s -= n;
    int h = prev(mp.end())->first;
    for (auto it = mp.end(); --it != mp.begin(); ) {
        h -= it->second;
        if (h > prev(it)->first) {
            s -= h - prev(it)->first;
            h = prev(it)->first;
        }
    } 
    cout << s << endl;
}
