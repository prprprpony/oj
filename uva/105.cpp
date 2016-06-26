#include <cstdio>
#include <iostream>
#define maxn 10005
using namespace std;

int main()
{
    int v[ maxn ] = {0};
    int l,h,r,maxr=0;

    while( scanf("%d%d%d",&l,&h,&r) != EOF )
    {
        if( r > maxr )
            maxr=r;
 
        for(int i=l;i<r;i++)
            if( h > v[i] )
                v[i] = h;
    }
    
    int i=0;
    while( v[i] == 0 ) i++;
    printf("%d %d ",i,v[i]);
    i++;

    for(; i < maxr ; i++ )
    {
        if( v[i-1] != v[i] )
            printf("%d %d ", i , v[i] );
    }
    printf("%d 0\n",maxr);

    return 0;
}
