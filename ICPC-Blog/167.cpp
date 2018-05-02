#include<cstdio>
int main()
{
    int n = 2e5;
    printf("%d\n",n);
    for (int i = 1; i <= n; ++i)
        printf("%d%c",i," \n"[i==n]);
}
