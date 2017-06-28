#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+87;
int a[N];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
        scanf("%d",a+i);
    sort(a,a+n);
    int mn = 2.1e9, c = 0;
    for (int i = 1; i < n; ++i)
        if (a[i]-a[i-1] < mn) {
            mn = a[i]-a[i-1];
            c=1;
        } else if (a[i]-a[i-1] == mn) {
            ++c;
        }
    printf("%d %d\n",mn,c);
}
