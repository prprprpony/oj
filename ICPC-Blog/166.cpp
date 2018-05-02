#include<cstdio>
const int N = 2e5 + 87;
int a[N],s[N],n,tp;
int main()
{
    scanf("%d",&n);
    long long ans = 0;
    s[tp++] = -1;
    for (int i = 0; i < n; ++i) {
        scanf("%d",a+i);
        while (tp > 1 && a[i] >= a[s[tp-1]])
            --tp;
        ans += i - s[tp-1];
        s[tp++] = i;
    }
    printf("%lld\n",ans);
}
