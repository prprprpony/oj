#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while( scanf("%d",&n) != EOF )
    {
        int rec[n][n];
        int column_sum[n][n];
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                scanf("%d",&rec[i][j]);
        int max_sum = rec[0][0];

        for(int j = 0;j < n;j++)
            column_sum[0][j] = rec[0][j];
        for(int i = 1;i < n;i++)
            for(int j = 0;j < n;j++)
                column_sum[i][j] = column_sum[i-1][j] + rec[i][j];

        for(int i = 0;i < n;i++)
            for(int j = i;j < n;j++)
            {
                int cur_sum = 0;
                for(int k = 0;k < n;k++)
                {
                    cur_sum += ( column_sum[j][k] - ( (i > 0) ? column_sum[i-1][k] : 0 )  );
                    max_sum = max( max_sum , cur_sum );
                    if( cur_sum < 0 )
                        cur_sum = 0;
                }
            }

        printf("%d\n",max_sum);
    }
    return 0;
}
