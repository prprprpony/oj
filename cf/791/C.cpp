#include <bits/stdc++.h>
using namespace std;
const int N  = 54;
char s[N];
int a[N];
char * name(int x)
{
    s[0] = 'A'+x%26;
    x/=26;
    int i = 1;
    for  (; x; ++i, x/=26)
        s[i] = 'a'+x%26;
    s[i] = '\0';
    return s;
}
int main()
{
    int n,k;
    scanf("%d%d%s",&n,&k,s);
    int l;
    if (s[0] == 'Y') {
        for (int i = 0; i < k; ++i)
            a[i] = i;
        l = 0;
    } else {
        a[0] = 0;
        for (int i = 1; i < k; ++i)
            a[i] = i - 1;
        l = k-1;
    }
    for (int i = k; i < n; ++i) {
        scanf("%s",s);
        if (s[0] == 'Y') {
            a[i] = l;
            l = a[i-k+1];
        } else {
            a[i] = a[i-k+1];
        }
    }
    for (int i = 0; i < n; ++i)
        printf("%s%c",name(a[i]), " \n"[i==n-1]);
/*
Y N Y
0 1 2 1 0
N Y N Y
0 0 1 2 1 0
N N N Y
0 0 1 2 0 1
*/
}
