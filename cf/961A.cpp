#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        ++v[x-1];
    }
    cout << *min_element(begin(v),end(v)) << endl;
}
