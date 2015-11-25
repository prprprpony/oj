#include <cstdio>
using namespace std;
bool nxt_comb( int* arr, int n , int m )
{
    for(int i=m-1;i>=0;i--)
    {
        if( arr[i] != ( n-(m-i-1) )  )
        {
            arr[i]++;
            for(int j=i+1;j<m;j++)
                arr[j]=arr[j-1]+1;
            return true;
        }
    }
    return false;
}
int main()
{
    int t;
    while( scanf("%d",&t) != EOF )
    {
        int n;
        while(t--)
        {
            scanf("%d",&n);
            printf("{0}\n");
            for(int i=1;i<=n;i++)
            {
                int num[i];
                for(int j=0;j<i;j++)
                {
                    num[j]=j+1;
                }

                do
                {
                    putchar('{');
                    for(int j=0;j<i;j++)
                    {
                        if(j!=0)putchar(',');
                        printf("%d",num[j]);
                    }
                    printf("}\n");
                }while( nxt_comb(num,n,i) );
            }
            putchar('\n');

        }
    }

    return 0;
}
