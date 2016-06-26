#include <cstdio>
#include <cmath>
#define MAXN 2147483647
#define size 46345
using namespace std;

bool seive[ size ] = {0};
int prime[size/2],size_prime=0;

bool isprime( int n )
{
    if( n < size )return !seive[n];
    else
    {
        int sqrtn=(int)sqrt(n) + 1 ;
        for(int i=0; prime[i] < sqrtn && i < size_prime ;i++)
        {
            if( (n%prime[i]) ==0 )return false;
        }
        return true;
    }
}
 
int main()
{
    seive[0]=true;
    seive[1]=true;

    for(int i=2 ; i < (int)sqrt(size) + 1 ; i++)
    {
        if( !seive[i] )
        {
            prime[size_prime++]=i;
            for(int j=i*i ; j < size ; j+=i )
                seive[j]=true;
        }
    }
    for(int i=prime[size_prime-1]+1;i<size;i++)
    {
        if(seive[i])continue;
        else prime[size_prime++]=i;
    }
        
    int n;
    while( scanf("%d",&n) != EOF )
    {
        if( isprime( n ) )printf("質數\n");
        else printf("非質數\n");
    }

    return 0;
}
