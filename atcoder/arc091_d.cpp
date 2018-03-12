#include<bits/stdc++.h>
using namespace std;
int sg(int a,int k)
{
    int w = a/k, r = a%k;
    int d = r / (w+1);
    return r % (w+1) ? sg(a - (w+1) * (d+1),k) : w;
}
int main()
{
    int n,s=0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a,k;
        cin >> a >> k;
        s ^= sg(a,k);
    }
    cout << (s ? "Takahashi" : "Aoki") << endl;
}
