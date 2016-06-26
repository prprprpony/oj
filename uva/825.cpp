#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    int t, w, n;
    bool first = true;
    string s;
    scanf("%d ",&t);
    while (t--) {
        scanf("%d%d ", &w, &n);
        vector< vector<int> > ways(w + 1, vector<int>(n+1, 0));
        vector< vector<bool> > ban(w + 1, vector<bool>(n+1, false));
        for (int i = 0, r, c; i < w; i++) {
            scanf("%d", &r);
            getline(cin, s);
            stringstream ss(s);
            while (ss >> c)
                ban[r][c] = true;
        }
/*
        for (int r = 1, b; r <= w; r++)
            for (int c = 1; c <= n; c++)
                if (ban[r][c])
                    printf("ban[%d][%d]\n", r, c);
*/
        for (int r = 1; r <= w && !ban[r][1]; r++)
            ways[r][1] = 1;
        for (int c = 1; c <= n && !ban[1][c]; c++)
            ways[1][c] = 1;
        for (int r = 2; r <= w; r++)
            for (int c = 2; c <= n; c++)
                if (!ban[r][c])
                    ways[r][c] = ways[r-1][c] + ways[r][c-1];
        if (first)
            first = false;
        else
            putchar('\n');
        printf("%d\n", ways[w][n]);
    }

    return 0;
}
