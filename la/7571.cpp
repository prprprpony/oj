#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int f[6];
inline int nm(int a) {return (a%M+M)%M;}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d%d%d",f,f+1,&n);
        n = (n-1) % 6;
        for (int i = 2; i <= n; ++i)
            f[i] = f[i-1] - f[i-2];
        printf("%d\n",nm(f[n]));
    }
}
