#include<bits/stdc++.h>
using namespace std;
int f(int n,int q)
{
    if (n == 1)
        return 1;
    int k = n/2;
    if (q <= k)
        return n-k+f(k,k-q+1);
    else
        return f(n-k,n-q+1);
}
int main()
{
    int n,q;
    cin >> n >> q;
    cout << f(n,q) << endl;
}
