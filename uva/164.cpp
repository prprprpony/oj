#include <bits/stdc++.h>
#define MAXN 25
using namespace std;

int d[MAXN][MAXN];
char p[MAXN][MAXN];
string a, b;

int main()
{
    while (cin >> a && a[0] != '#') {
        cin >> b;
        d[a.size()][b.size()] = 0;
        for (int i = 0; i < b.size(); i++) {
            d[a.size()][i] = b.size() - i;
            p[a.size()][i] = 'I';
        }
        for (int i = 0; i < a.size(); i++) {
            d[i][b.size()] = a.size() - i;
            p[i][b.size()] = 'D';
        }
        for (int i = a.size()-1; i >= 0; i--)
            for (int j = b.size()-1; j >= 0; j--)
                if (a[i] == b[j]) {
                    d[i][j] = d[i+1][j+1];
                    p[i][j] = 'N';
                } else {
                    d[i][j] = d[i+1][j];
                    p[i][j] = 'D';
                    if (d[i+1][j+1] < d[i][j]) {
                        d[i][j] = d[i+1][j+1];
                        p[i][j] = 'C';
                    }
                    if (d[i][j+1] < d[i][j]) {
                        d[i][j] = d[i][j+1];
                        p[i][j] = 'I';
                    }
                    d[i][j]++;
                }
        // printf("%d\n", d[0][0]);

        for (int i = 0, j = 0, inc = 0, c, t, pos; i < a.size() || j < b.size(); ) {
            pos = i + inc;
            c = p[i][j];
            switch (c) {
            case 'D':
                t = a[i];
                i++;
                inc--;
                break;
            case 'I':
                t = b[j];
                inc++;
                j++;
                break;
            case 'C':
                t = b[j];
                i++;
                j++;
                break;
            case 'N':
                i++;
                j++;
                continue;
            }
            printf("%c%c%02d", c, t, pos + 1);
        }
        puts("E");
    }

    return 0;
}
