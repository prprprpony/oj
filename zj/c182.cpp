#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+87;
bool a[N];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        int x;
        while (!isdigit(x = getchar()));
        a[i] = x=='1';
    }
    int ans=0;
    for (int i = 1; i <= n; ++i)
        if (a[i]) {
            ++ans;
            for (int j = i; j <= n; j += i)
                a[j] = !a[j];
        }
    printf("%d\n",ans);
}
