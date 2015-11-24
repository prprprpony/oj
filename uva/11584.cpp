#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#define INF (1<<30)
using namespace std;

string strpart(string s, int a, int b)
{
    string r;
    for (int i = a; i <= b; ++i)
        r.push_back(s[i]);
    return r;
}




int main()
{
    string s;
    while (cin >> s) {
        int l = s.length();
        bool pali[l][l];
        memset(pali, 0, sizeof(pali));
        int d[l];

        for (int i = 0; i < l; ++i) {
            for (int j = i, k = i; (j >= 0) && (k < l) && (s[j] == s[k]); --j, ++k)
                pali[j][k] = true;
            for (int j = i, k = i + 1; (j >= 0) && (k < l) && (s[j] == s[k]); --j, ++k)
                pali[j][k] = true;
        }

        for (int i = 0; i < l; ++i) {
            if (pali[0][i]) {
                d[i] = 1;
                continue;
            }
            d[i] = INF;
            for (int j = 1; j <= i; ++j)
                if (pali[j][i])
                    d[i] = min(d[i], d[j-1] + 1);
        }

        printf("%d\n", d[l-1]);
    }
    return 0;
}
