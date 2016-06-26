#include <cstdio>
using namespace std;
const int maxn = 1.1e5;
char s[maxn];

inline int max(int a, int b) {return a > b ? a : b;}

int main()
{
    int n, k;
    scanf("%d%d ", &n, &k);
    fgets(s, sizeof(s), stdin);
    int ans = 0;
    for (char c = 'a'; c <= 'b'; ++c) {
        for (int l = 0, r = -1, no = 0; r < 0 || s[r] != '\n'; ) {
            while (no <= k && s[r] != '\n')
                if (s[++r] != c)
                    ++no;
            ans = max(ans, r - l);
            while (s[l] == c)
                ++l;
            ++l;
            --no;
        }
    }
    printf("%d\n", ans);
}
