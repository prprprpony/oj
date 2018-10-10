#include<bits/stdc++.h>
using namespace std;
const int N = 100002;
char a[N],b[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    while (cin >> n >> k) {
        cin >> a;
        int j = 0;
        for (int i = 0; i <= k; ++i)
            if (a[i] < a[j] && a[i] != '0')
                j = i;
        int l=1,r=1;
        b[0] = a[j];
        while (++j < n) {
            while (r - l && b[r-1] > a[j])
                --r;
            b[r++] = a[j];
            if (j - l == k)
                ++l;
        }
        b[l++] = '\n';
        b[l++] = '\0';
        cout << b;
    }
}
