#include<bits/stdc++.h>
using namespace std;
const int N = 5566;
char s[N];
int main()
{
    int n;
    scanf("%d ",&n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            s[j] = getchar();
        putchar(s[i]);
    }
    puts("");
}
