#include <cstdio>
using namespace std;
typedef long long LL;

LL num_0( LL number )
{
    LL sum = 1;
    for( LL base = 1 , right = 0 ;  number > 0; base *= 10 )
    {
        int cur = number % 10 ;
        number /= 10;
        if( cur )
            sum += ( number * base );
        else
            sum += (  ( number - 1 ) *  base + right + 1 ) ;
        right += (base * cur);
    }
    return sum;
}

int main()
{
    LL  m,n;

    /*
    while( scanf("%u",&m) && m >= 0  )
    {
        printf( "%u\n" , num_0( m ) );
    }
    */

    while( scanf("%lld%lld",&m,&n) && m >= 0 && n >= 0 && n >= m )
    {
        printf( "%lld\n" , num_0( n ) -( ( m > 0 ) ? num_0( m-1 ) : 0 ) );
    }

    return 0;
}
