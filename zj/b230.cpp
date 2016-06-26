#include <cstdio>
#include <vector>
#define MAXN 1849
using namespace std;

vector<bool> iscn(MAXN, true);
vector<int> cn;

int main()
{
    int k;
    for (int i = 3; 3 * i + 2 < MAXN ; i++) // 2i + 1i + 2 = 3i + 2
        for (int j = 2; j < i && i * j + i + j < MAXN; j++) // i*j + j*1 + i*1
            for (int k = 1; k < j && i * j + k * (i + j) < MAXN; k++)
                iscn[i*j + i*k + j*k] = false;
    for (int i = 1; i < MAXN && cn.size() < 65; i++)
    //for (int i = 1; i < MAXN; i++)
        if (iscn[i])
            cn.push_back(i);
///*
    while (scanf("%d", &k) == 1)
        printf("%d\n", cn[k-1]);
//*/
/*
    printf("number of cn in [1..%d] = %d\n", MAXN - 1, cn.size());
    for (int i = 0; i < 65; i++)
        printf("cn[%d] = %d\n", i+1, cn[i]);
*/

    return 0;
}
