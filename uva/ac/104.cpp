#include<iostream>
#include<cstdio>
#include<string>
#include <vector>
using namespace std;

int n;
double r[25][25];

struct arbitrage{
    vector<int> seq;
    double profit;
};


void iddfs( arbitrage a ,arbitrage& min )
{
    if( ( a.profit * r[ a.seq.back() ][ a.seq.front() ] ) >= 1.01 )
    {
        min = a;
        return;
    }

    for( int i = 0 ; i < n ; i++ )
    {
        if( a.seq.size() >= (min.seq.size()-1) ) break;
        if( i != a.seq.back() )
        {
            double ori = a.profit;
            a.profit *= r[ a.seq.back() ][ i ] ;
            if( a.profit > 1.0 )
            {
                a.seq.push_back( i );
                iddfs( a , min );
                a.seq.pop_back();
            }
            a.profit = ori;
        }
    }

    return;
}

int main()
{
 
    while(scanf("%d",&n)!=EOF)
    {
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
            {
                if(j==i)r[i][j] = 1.0;
                else scanf("%lf",&r[i][j]);
            }

        arbitrage min;
        min.seq = vector<int>( n+1 , 0 );

        for(int i=0;i<n;i++)
        {
            arbitrage a;
            a.seq.push_back( i );
            a.profit = 1.0;
            iddfs( a , min );
        }

        if( min.seq.size() != (n+1) )
        {
            for(int i = 0 ; i < min.seq.size() ; i++ )
                printf("%d ",min.seq[i]+1);
            printf("%d\n",min.seq[0]+1);
        }
        else
        {
            printf("no arbitrage sequence exists\n");
        }
   }

    return 0;
}
