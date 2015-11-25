#include<cstdio>
using namespace std;
int main()
{
    int n,m;
    while( scanf("%d%d",&n,&m) != EOF )
    {
        if( m==0 || m==n )printf("1\n");
        else if( m==1 || m==(n-1) )printf("%d\n",n);
        else
        {
            m =( m > (n-m) )? n-m : m ;
            int ans=n;
            for(int i=2;i<=m;i++)
                ans=ans*(--n)/i;
            printf("%d\n",ans);
        }
    }

    return 0;
}
