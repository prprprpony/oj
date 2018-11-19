#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    iota(begin(x),end(x),1);
    int ans = 0;
    do {
        int v = 0;
        for (int u : x)
            if (v < u)
                ++v;
            else if (v > u)
                --v;
        ans += v == (n+1)/2 || v == (n+2)/2;
    } while (next_permutation(begin(x),end(x)));
    cout << ans << endl; 
}
