#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int k;
    cin >> k;
    while (k--) {
        int n, m;
        cin >> n >> m;
        cout << 2*(min(n,m)-1) << '\n';
    }
}
