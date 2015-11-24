#include <cstdio>
#include <vector>
#include <cstring>
#define WIDTH 8
using namespace std;

vector< vector<int> > eq; // eq[i][r] = c ->  ans[i] have a queen on (r,c)
vector<int> s(8);
bool col[8];
bool slash[2][15]; // slash[0] : / slash[1] : \

void find_eq(int r)
{
    if (r == WIDTH) {
        eq.push_back(s);
        return;
    }
    for (int c = 0; c < WIDTH; c++) {
        if (!col[c] && !slash[0][r+c] && !slash[1][r - c + WIDTH - 1]) {
            col[c] = slash[0][r+c] = slash[1][r - c + WIDTH - 1] = true;
            s[r] = c;
            find_eq(r+1);
            col[c] = slash[0][r+c] = slash[1][r - c + WIDTH - 1] = false;
        }
    }
}

int main()
{
    memset(col, 0, sizeof(col));
    memset(slash, 0, sizeof(slash));
    find_eq(0);
/*
    printf("%d\n", eq.size());
    for (int i = 0; i < 10 && i < eq.size(); i++) {
        printf("Ans %d:\n", i);
        for (int r = 0; r < WIDTH; r++) {
            for (int c = 0; c < WIDTH; c++)
                putchar(eq[i][r] != c ? '_' : 'Q');
            putchar('\n');
        }
    }
*/
    int k;
    int b[WIDTH][WIDTH];
    int maxsum;

    while (scanf("%d", &k) == 1) {
        while (k--) {
            maxsum = 0;
            for (int r = 0; r < WIDTH; r++)
                for (int c = 0; c < WIDTH; c++)
                    scanf("%d", &b[r][c]);
            for (int i = 0; i < eq.size(); i++) {
                int sum = 0;
                for (int r = 0; r < WIDTH; r++)
                    sum += b[r][eq[i][r]];
                maxsum = max(maxsum, sum);
            }
            printf("%5d\n", maxsum);
        }
    }

    return 0;
}
