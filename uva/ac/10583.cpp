#include <cstdio>
#include <algorithm>
#define MAXN 50005
using namespace std;

int s[MAXN];
int num[MAXN];
int m,n,tot,num_cases=0;

/*recursive
int get_set(int a)
{
    return ( s[a] == a ) ? a : ( s[a] = get_set(s[a]) );
}
*/

//inplace
int get_set(int a)
{
    int it = a,nxt;
    while( s[a] != a )
        a = s[a];
    while( s[it] != a )
    {
        nxt = s[it];
        s[it] = a;
        it = nxt;
    }

    return a;
}

void link( int a, int b)
{
    a = get_set(a);
    b = get_set(b);
    if( a != b )
    {
        tot--;

        if( num[ a ] > num[ b ] )
            swap(a,b);

        num[ b ] += num[ a ];
        num[ a ] = 0;
        s[ a ] = b;
    }
}

int main()
{
    while(scanf("%d%d",&n,&m), n)
    {
        num_cases++;
        tot = n;
        for(int i = 1; i <= n; i++)
        {
            s[i] = i;
            num[i] = 1;
        }

        for(int i = 0, a, b; i < m; i++)
        {
            scanf("%d%d",&a,&b);
            link(a,b);
        }

        printf("Case %d: %d\n",num_cases,tot);
    }

    return 0;
}
