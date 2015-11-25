#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
using namespace std;

int song[3];

struct Idol
{
    int u;
    double s;
    double p;
    double c;
    double score;

    friend bool operator > (const Idol &a, const Idol & b)
    {
        return a.score > b.score;
    }
    void calc()
    {
        score = song[0] * s + song[1] * p + song[2] * c;
    }
};

bool ucmp(const Idol &a, const Idol &b)
{
    return a.u < b.u;
}


int main(void)
{
    int t, n, m, c;
    Idol idol[25];
    double sum;
    cin >> t;
    while (t--) {
        scanf("%d,%d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%d,%lf,%lf,%lf ", &idol[i].u, &idol[i].s, &idol[i].p, &idol[i].c);
        memset(song, 0, sizeof(song));
        for (int i = 0; i < m; i++) {
            c = getchar();
            switch (c) {
                case 's':
                    song[0]++;
                    break;
                case 'p':
                    song[1]++;
                    break;
                case 'c':
                    song[2]++;
                    break;
            }
            getchar();
        }
        for (int i = 0; i < n; i++)
            idol[i].calc();
        sort(idol, idol + n, greater<Idol>());
        sort(idol, idol + 9, ucmp);
        sum  = 0.0;
        for (int i = 0; i < 9; i++)
            sum += idol[i].score;
        sum /= 9.0;
        printf("%.3f\n", (int)(sum * 1000.0 + 0.5) / 1000.0);
        for (int i = 0; i < 9; i++)
            printf("%d%c", idol[i].u, i != 8 ? ',' : '\n');
    }
    return 0;
}
