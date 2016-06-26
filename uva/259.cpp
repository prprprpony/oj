#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

const int nx = 10;
const int max_ny = 26 * 9;
int ny;

bool g[nx][max_ny];
char y[max_ny];
int mx[nx], my[max_ny];
bool vy[max_ny];

bool dfs(int x)
{
    for (int y = 0; y < ny; ++y) {
        if (g[x][y] && !vy[y]) {
            vy[y] = true;
            if (my[y] == -1 || dfs(my[y])) {
                mx[x] = y;
                my[y] = x;
                return true;
            }
        }
    }
    return false;
}

int bipartite_matching()
{
    memset(mx, -1, sizeof(mx));
    memset(my, -1, sizeof(my));
    
    int c = 0;
    for (int x = 0; x < nx; ++x) {
        memset(vy, 0, ny * sizeof(bool));
        if (dfs(x))
            ++c;
    }
    return c;
}

int main()
{
    int c;
    while ((c = getchar()) != EOF) {
        memset(g, 0, sizeof(g));
        bool first = true;
        ny = 0;
        while (first || isalpha(c = getchar())) {
            if (first)
                first = false;
            int num = getchar() - '0';
            memset(y + ny, c, num);
            getchar();
            int com;
            while ((com = getchar()) != ';')
                for (int i = 0; i < num; ++i)
                    g[com - '0'][ny + i] = true;
            getchar();
            ny += num;
        }
        if (bipartite_matching() < ny)
            puts("!");
        else {
            for (int x = 0; x < nx; ++x)
                putchar(mx[x] != -1 ? y[mx[x]] : '_');
            putchar('\n');
        }
    }
}
