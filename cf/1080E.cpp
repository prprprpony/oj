#include<bits/stdc++.h>
using namespace std;
template<class T>
void Zpal(const T *s, int len, int *z) {
    // Only odd palindrome len is considered
    // z[i] means that the longest odd palindrom centered at
    // i is [i-z[i] .. i+z[i]]
    z[0] = 0;
    for (int b=0, i=1; i<len; i++) {
        if (z[b] + b >= i) z[i] = min(z[2*b-i], b+z[b]-i);
        else z[i] = 0;
        while (i+z[i]+1 < len and i-z[i]-1 >= 0 and 
               s[i+z[i]+1] == s[i-z[i]-1]) z[i] ++;
        if (z[i] + i > z[b] + b) b = i;
    }
}
typedef array<int,27> ar;
const int N = 255;
ar s[N*2];
char g[N][N];
int n,m,oc[N],z[N*2],ans;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) 
        cin >> g[i];
    for (int jl=0;jl<m;++jl) {
        fill_n(s,2*n+1,ar());
        memset(oc,0,sizeof oc);
        for (int jr=jl;jr<m;++jr) {
            for (int i = 0; i < n; ++i) {
                int x=g[i][jr]-'a';
                oc[i] += s[i*2+1][x]++ % 2 ? -1 : 1;
                s[i*2+1][26] = oc[i] > 1 ? -i-1 : 0;
            }
            Zpal(s,2*n+1,z);
            for (int i = 1; i <= 2*n-1; ++i)
                if (i & 1) {
                    if (s[i][26] < 0)
                        continue;
                    ans += (z[i]+1)/2;
                } else {
                    ans += z[i]/2;
                }
        }
    }
    cout << ans << endl;
}
