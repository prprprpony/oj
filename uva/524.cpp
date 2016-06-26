#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#define MAX 1000
using namespace std;

bool sieve[MAX]={0};
vector<int> prime;

int n;
bool vis[ MAX / 2 + MAX % 2 + 1 ]={0};
int ans[ MAX / 2 + MAX % 2 + 1 ]={0};

void prime_table()
{
    sieve[0]=sieve[1]=1;
    for( int i = 2 ; i < MAX ; i++ )
    {
        if(!sieve[i])
            prime.push_back(i);
        for( vector<int>::iterator it=prime.begin() ; it!=prime.end() ; it++ )
        {
            int num = i * (*it);
            if( num >= MAX )break;
            else sieve[ num ] = 1;

            if( !( i % (*it) ) ) break;
        }
    }
}

void test_prime()
{
    printf("Seive:\n");
    for( int i = 0 ; i < MAX ; i++ )
        if(!sieve[i])printf("%d ",i);
    printf("\n");
    printf("Prime:\n");
    for( int i = 0 ; i < prime.size() ; i++ )
        printf("%d ",prime[i]);
    printf("\n");
}

int dfs( int cur , int lvl )
{
    ans[ lvl ] = cur;

    if( lvl == n && !sieve[ ans[ n ] + ans[ 1 ] ] )
    {
        printf("%d",ans[1]);
        for( int i = 2 ; i <= n ; i++ )
            printf(" %d",ans[i]);
        printf("\n");
    }
    else
    {
        for( int i = 2 ; i <= n ; i++ )
            if( !vis[i] && !sieve[ i + cur ] )
            {
                vis[i]=true;
                dfs( i , lvl+1 );
                vis[i]=false;
            }
    }
}

int main()
{
    int c=0;
    prime_table();

    while( scanf("%d",&n) != EOF )
    {
        if(c!=0)printf("\n");
        printf("Case %d:\n",++c);

        memset( vis , 0 , sizeof(vis) );
        memset( ans , 0 , sizeof(ans) );

        vis[1]=1;
        dfs( 1 , 1 );

    }

    return 0;
}
