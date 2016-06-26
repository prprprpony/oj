#include <cstdio>
#include <algorithm>
using namespace std;

struct range{
    int s;
    int e;
    int first_neg;
    int last_neg;
    int num_neg;
    long long pro;

    range()
    {
        s = -1;
        e = -1;
        first_neg = -1;
        last_neg = -1;
        num_neg = 0;
        pro = 1;
    }
};

int main()
{
    int n,m=0;
    while( scanf("%d",&n) != EOF )
    {
        int s[n];
        long long max_p = 0;
        range r[18];
        int rn = 0;
        
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&s[i]);
            
            if( s[i] != 0 )
            {
                r[rn].pro *= s[i];

                if( r[rn].s == -1 )
                    r[rn].s = i;

                if( s[i] < 0 )
                {
                    if( r[rn].first_neg == -1 )
                        r[rn].first_neg = i;

                    r[rn].last_neg = i;
                    r[rn].num_neg++;
                }
            }
            else if(r[rn].s != -1)
                r[rn++].e = i;
        }
        
        if( r[rn].s != -1 && r[rn].e == -1 )
            r[rn++].e = n;
        
        for(int i=0; i < rn; i++)
        {
            if( r[i].num_neg & 1 && (r[i].e-r[i].s) > 1 )
            {
                long long p = r[i].pro;
                for(int j = r[i].s; j <= r[i].first_neg; j++)
                    p /= s[j];
                max_p = max( max_p , p );

                p = r[i].pro;
                for(int j = r[i].last_neg; j < r[i].e; j++)
                    p /= s[j];
                max_p = max( max_p , p );
            }
            else
                max_p = max( max_p , r[i].pro );
        }

        printf("Case #%d: The maximum product is %lld.\n\n",++m,max_p);

    }

    return 0;
}
