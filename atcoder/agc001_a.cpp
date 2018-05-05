#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(2*n);
    for (int & L : a)
        cin >> L;
    sort(begin(a),end(a));
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += a[i*2];
    cout << ans << endl;
}
