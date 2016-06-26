#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct B
{
    int numBox;
    int* side;
    int numMaxNest;
    B* outer;
};
int k,n;

bool cmp_side_greater( B a , B b )
{
    for( int i = n-1 ; i >= 0 ; i-- )
        if(a.side[i]>b.side[i])
            return true;

    return false;
}

//whether right can nest in left or not
bool nestable(B left,B right)
{
    for(int i = n-1 ; i >= 0 ; i--)
    {
        if( !( left.side[i] > right.side[i] ) )
            return false;
    }
    return true;
}

int main()
{
    while( scanf("%d%d",&k,&n) != EOF )
    {
        int box[k][n];
        B ans[k];
        for( int b = 0 ; b < k ; b++ )
        {
            for(int i = 0 ; i < n ; i++ )
                scanf("%d",&box[b][i]);

            sort(box[b],box[b]+n);

            ans[b].numBox = b+1;
            ans[b].side = box[b];
            ans[b].numMaxNest = 1;
            ans[b].outer=NULL;
        }
        sort( ans , ans + k , cmp_side_greater );
        
//        for(int b=0;b<k;b++)
//            ans[b].outer = &ans[b];

        int MAXNESTNUM = 1 ;
        B* inner=&ans[0];
        for(int i=1;i<k;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if( nestable( ans[j] , ans[i] ) && ( (ans[j].numMaxNest+1) > ans[i].numMaxNest ) )
                {
                    ans[i].numMaxNest = ans[j].numMaxNest+1;
                    ans[i].outer = &ans[j];
                    if( ans[i].numMaxNest > MAXNESTNUM )
                    {
                        MAXNESTNUM=ans[i].numMaxNest;
                        inner=&ans[i];
                    }
                }
            }
        }

        printf("%d\n%d", MAXNESTNUM , inner->numBox );
        inner=(inner->outer);
        
        /* test
        putchar('\n');
        for(int i=0;i<k;i++)
        {
            printf("ans[%d]={box[%d],outer=%d,numMaxNest=%d}\n",i,ans[i].numBox, ans[i].outer -> numBox , ans[i].numMaxNest);
        }
        */

        for(; inner != NULL ; inner = (inner->outer) )
        {
            printf(" %d", inner->numBox );
        }
        putchar('\n');

    }

    return 0;
}
