#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAX 32768
using namespace std;

int n;
bool vis[MAX]={0};
int min_d;
int a[MAX] = {0};
int* a_end = a;

char ans[1000]={0};
char* ans_end = ans;

int h(int n)
{
    int lead_pos = -1;
    int one_num = 0;
    for(int i = (sizeof(int)<<3)-1 ; i >= 0 ; i-- )
    {
        if( (1<<i)&n )
        {
            if( lead_pos == -1 )
                lead_pos =  i ;
            else
                one_num++;
        }
    }
    return min( lead_pos + one_num , ((lead_pos+1)<<1) - one_num );
}

int B()
{
    return *(a_end-1);
}

void iddfs( int d )
{
    if( d >= (min_d-1) )return;
    if(  ( B() * (1<<(min_d - d))) < n )return;
    if( vis[ abs( n - B() ) ] )
    {
        min_d =  d+1 ;
int len=(n>B()) ?sprintf(ans_end,"x^%d = x^%d * x^%d\n",n,B(),n-B())
                    :sprintf(ans_end,"x^%d = x^%d / x^%d\n",n,B(),B()-n);
ans_end+=len;

printf("d=%d\n",min_d);
fputs(ans,stdout);
putchar('\n');

ans_end-=len;
*ans_end='\0';

        return;
    }

//    for(int i = B(); i > 0 ; i-- )
//        if(vis[i])
/*
int i = B();
            for(int j = i ; j > 0 ; j-- )
                if( vis[j] )
                    for( int a = 1 ; a >= -1 ; a -= 2 )
                    {
                        int gen = i + a * j ;
                        if( gen > 0 && !vis[ gen ] )
                        {
                            int tmpB = B();
                            B() = max( B() , gen );
if(B() >= MAX)printf("ERROR\n");
                            vis[gen]=true;
                            iddfs(d+1);
                            vis[gen]=false;
                            B() = tmpB;
                        }
                    }
*/


/*
    for(int t = 0; t < 2; t++)
    {
        if( (t==0) == (n>B()) )
        {
            for(int i=B();i>0;i--)
            {
               if(vis[i])
                {
                    B()+=i;
                    if( !vis[B()] )
                    {
int len=sprintf(ans_end,"x^%d = x^%d * x^%d\n",B(),B()-i,i);
ans_end+=len;
                        vis[B()]=true;
                        iddfs(d+1);
                        vis[B()]=false;
ans_end-=len;
*ans_end='\0';
                    }
                    B()-=i;
                    if( d >= (min_d-1) )return;
                    if( (B() * (1<<(min_d - d))) < n )return;
                }
            }
        }
        else
        {
            for(int j=1;j<B();j++)
            {
                if(vis[j])
                {
                    int tmp = B()-j;
                    if( !vis[tmp] )
                    {
int len=sprintf(ans_end,"x^%d = x^%d / x^%d\n",B()-j,B(),j);
ans_end+=len;
                        vis[tmp]=true;
                        iddfs(d+1);
                        vis[tmp]=false;
ans_end-=len;
*ans_end='\0';
                        if( d >= (min_d-1) )return;
                        if( (B() * (1<<(min_d - d))) < n )return;
                   }
                }
            }
        }
    }
*/

    for(int t = 1; t >= -1; t -= 2)
        for(int* i = a_end-1; i >= a; i--)
        {
            for(int* j = i; j >= a; j--)
            {
                int cur = (*i) + t * (*j);
                if( cur > 0 && !vis[cur] )
                {
                    int* lb = lower_bound(a,a_end,cur);
                    int length = a_end - lb;
                    int tmp[length];
                    memcpy( tmp, lb, length*sizeof(int) );
                    *lb=cur;
                    a_end++;
                    memcpy( lb+1, tmp, length*sizeof(int) );
                    
int len = ( cur > *i ) ? sprintf(ans_end,"x^%d = x^%d * x^%d\n",cur,*i,*j)
                       : sprintf(ans_end,"x^%d = x^%d / x^%d\n",cur,*i,*j);
ans_end+=len;

                    vis[cur] = true;
                    iddfs(d+1);
                    vis[cur]=false;

ans_end-=len;
*ans_end='\0';
 
                    memcpy( lb, tmp, length*sizeof(int) );
                    a_end--;

                    if( d >= (min_d-1) )return;
                    if( (B() * (1<<(min_d - d))) < n )return;
                }
            }
        }

}

int main()
{
    vis[1]=true;
    *(a_end++)=1;
    while(scanf("%d",&n), n)
    {
        min_d = h(n);
printf("h(%d)=%d\n",n,min_d);
        iddfs(0);
        printf("%d\n",min_d);
    }
/*
    int m=0;
    for(int i=1;i<1001;i++)
        m=max(m,h(i));
    printf("%d\n",m);
*/
    return 0;
}
