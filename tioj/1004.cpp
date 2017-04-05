#include <bits/stdc++.h>
using namespace std;
int f(int n)
{
    return n==1 ? 1 : (n & 1) ? f(n>>1)<<1|1 : (f(n>>1)<<1)-1;
}
int main()
{
    int n;
    cin >> n;
    cout << f(n) << endl;
}
