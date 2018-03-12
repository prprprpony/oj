#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;
    cin >> n >> m;
    if (n < m)
        swap(n,m);
    if (m == 1)
        cout << (n == 1 ? 1 : n - 2) << endl;
    else
        cout << (n - 2) * (m - 2) << endl;
}
