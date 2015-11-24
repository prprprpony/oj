#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
#define INF 99999
using namespace std;

int main()
{
    int n,k;
    while( scanf("%d%d",&n,&k) != EOF )
    {
        int w[ n ][ 100 ][ 100 ];
        memset( w , 0 , sizeof(w) );
        int t[ n ];
        for( int i = 0 ; i <  n ; i ++ )
            scanf("%d%*[ \n\t]",&t[i]);
        for( int i = 0 ; i <  n ; i ++ )
        {
            vector<int> vis;
            char c;
            int v = 0;
            bool counting = false;
            while( ( c = getchar() ) != '\n' )
            {
                if( isdigit(c) )
                {
                    v = 10 * v + ( c - '0' );
                    counting = true;
                }
                else if( counting )
                {
                    vis.push_back(v);
                    vector<int>::iterator it=vis.begin();

                    while( *it != v )
                    {
                        w[i][*it][v] = t[i] * ( v - (*it) );
                        w[i][v][*it] = t[i] * ( v - (*it) );
                        it++;
                    }

                    v = 0 ;
                    counting = false ;
                }
            }
        }

        int d[n][100];
        memset(d,-1,sizeof(d));
        bool visit[n][100];
        memset(visit,0,sizeof(visit));

        for(int i=0;i<n;i++)
        {
            visit[i][0]=true;
            d[i][0]=0;
        }
        //Dijkstra? not finished yet
        while(1)
        {
            int Min=0,Min_lift;
            for(int i = 1 ; i < 100 ; i++)
                if( w[][i].size())
                {
                    for(int j=0 ; j<w[cur][i].size() ; j++ )
                    {
                        if(visit[ w[0][i][j].l ][i])continue;
                        if( ( Min && w[cur][i][j].l<Min ) || !Min )
                        {
                            Min=w[cur][i][j].l;
                            Min_lift=w[cur][i][j];
                        }
                    }
                }
        }


    }

    return 0;
}
