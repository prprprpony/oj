#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[3];
    cin >> n;
    for (int i = 0; i < 3; ++i)
        cin >> a[i];
    sort(a,a+3);
    int ans = n;
    do {
        int m = n;
        for (int i = 0; i < 3; ++i) 
            m *= (100 - a[i]) / 100.0;
        ans = min(ans, m);
    } while (next_permutation(a,a+3));
    cout << n - ans << '\n';
}
