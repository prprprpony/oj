#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cctype>
#define INF 1e8
using namespace std;
/*debug begin
int solveN;
end*/
enum DIR{S,U,L,R,D};

int dr[5]={0,-1,0,0,1},
    dc[5]={0,0,-1,1,0},
    id[26],
    id_bot,
    w,h,n;
int* ans;
struct coord
{
    int r;
    int c;

    bool operator==(const coord& a) const
    {
        return (r == a.r && c == a.c );
    }
};

inline int getid( char c )
{
    int num_alpha = toupper( c ) - 'A';

    if( id[ num_alpha ] == -1)
        id[ num_alpha ] = id_bot++;

    return id[ num_alpha ];
}

inline int pos_id( coord  pos )
{
    return pos.r * w + pos.c;
}

inline int hash(vector<coord> pos)
{
    int val=0,base=w*h;
    for( vector<coord>::iterator it = pos.begin() ; it!=pos.end() ; it++)
    {
        val *= base;
        val += pos_id(*it);
    }

    return val;
}

inline int num_stat()
{
    int val=1,num_pos=w*h;
    for(int b = 0 ; b < n ; b++ )
        val*=num_pos;
    return val;
}

bool next_dir( vector<int>& dir )
{
    int cur=n-1;
    while( cur!=-1 )
    {
        if( dir[cur] == 4 )
        {
            dir[cur]=0;
            cur--;
        }
        else
        {
            dir[cur]++;
            return true;
        }
    }
    return false;
}

inline int move( vector<char>& g , vector<int>& dir , vector<coord>& bot )
{
    vector< coord > pre(bot);
    for(int b = 0 ; b < n ; b++ )
    { 
        bot[ b ].r += dr[ dir[ b ] ];
        if( bot[ b ].r < 0 || bot[ b ].r >= h )return -1;
        bot[ b ].c += dc[ dir[ b ] ];
        if( bot[ b ].c < 0 || bot[ b ].c >= w )return -1;

        if( g[ pos_id( bot[b] ) ] == '#' )return -1;
    }

    for( int first = 0 ; first < n-1 ; first++ )
    {
        for( int second = first + 1 ; second < n ; second++ )
        {
            if( bot[ first ] == bot[ second ] )
                return -1;
            if( pre[ first ] == bot[ second ] && pre[ second ] == bot[ first ] )
                return -1;
        }
    }

    return 0;
}

/*debug  begin
inline int printg( vector<char>& g , vector<coord>& bot , vector<coord>&  target)
{
    int i=0;
    for(int b=0;b<n;b++)
    {
        g[ pos_id( bot[b] ) ] = 'a' + b ;
        g[ pos_id( target[b] ) ] = 'A' + b ;
    }
    while( i != (w*h) )
    {
        putchar(g[i]);
        if( (i % w) == ( w-1 ) )
            putchar('\n');
        i++;
    }
    putchar('\n');
    putchar('\n');
    for(int b=0;b<n;b++)
    {
        g[ pos_id( bot[b] ) ] = ' ';
        g[ pos_id( target[b] ) ] = ' ';
    }
    return 0;
}
end*/

/*debug 
inline int printdir(vector<int>& dir)
{
    for(int b=0 ;b<n;b++)
    {
        cout<<(char)('a'+b)<<":";
        switch( dir[b] )
        {
            case 0:
                putchar('S');
                break;
            case 1:
                putchar('U');
                break;
            case 2:
                putchar('L');
                break;
            case 3:
                putchar('R');
                break;
            case 4:
                putchar('D');
                break;
        }
        cout<<"\n";
    }
}
end*/

 
inline int solve( vector<char>& g , vector<coord>& bot , vector<int>& least , int steps , vector<coord>& target)
{
    /*debug begin
    cout<<"solve()#"<<solveN++<<endl;
    */
    

    vector<coord> current(bot);
    int* min = &least[ hash( bot ) ];

    if( steps < *min )
    {
        *min=steps;
   }
    else 
    {
       return -1;
       q
    }

    if( steps >= *ans )
    {
       return -1;
    }

    vector<int> dir(n,0);
    dir[ n-1 ] = 1;

    do{
        if( move( g , dir , bot ) != -1)
        {
            //printdir(dir);
            solve( g , bot , least , steps + 1 , target );
        }
        
        bot=current;
    } while( next_dir( dir ) );

    return 0;
}

int main()
{
    while( scanf( "%d%d%d" , &w , &h , &n )  && w && h && n )
    {
        while( getchar() != '\n' );

        //initialize variable begin:
        vector< char > g( h * w );
        vector< int > least( num_stat() , INF );
        vector<coord> bot(n),target(n);
        memset( id , -1 , sizeof(id) );
        id_bot=0;
        //end

        /*debug begin
        solveN=0;
        end*/

        // input
        for( coord cur={0,0} ; cur.r < h ; cur.r++ )
        {
            for( cur.c=0 ; cur.c < w ; cur.c++ )
            {
                char c;
                c=getchar();
                if( cur.c == (w-1) ) getchar();

                if( isalpha(c) )
                {
                    if( c>='a' && c<='z' )
                        bot[ getid( c ) ] = cur;
                    else target[ getid( c ) ] = cur;

                    c=' ';
                }

                g[ pos_id( cur ) ]=c;
            }
        }
        
        ///*
        ans = &least [ hash( target ) ];
        solve( g , bot , least , 0 , target);
        printf( "%d\n" , *ans );
        //*/


        /*test input
        for( coord cur={0,0} ; cur.r < h ; cur.r++ )
        {
            for( cur.c=0 ; cur.c < w ; cur.c++ )
            {
                putchar( g[ pos_id( cur ) ] );
                if( cur.c == (w-1) ) putchar('\n');
            }
        }
        cout<<"\npos={row,column}\n\n";
        for(int i=0;i<26;i++)
        {
            if(id[i]!=-1)
            {
                cout<<"id of '"<< (char)('a'+i ) <<"' = "<<id[i]<<endl;
                cout<<"current pos ={"<<bot[ id[i] ].r<<','<<bot[ id[i] ].c<<"}\n";
                cout<<"target pos ={"<<target[ id[i] ].r<<','<<target[ id[i] ].c<<"}\n\n";

            }
        }
        */
 
        //function test:
        //cout<<num_stat()<<endl;

/*  next_dir()
        vector<int> dir(n,0);
        dir[n-1]=1;
        do
        {
            for( vector<int>::iterator it=dir.begin();it!=dir.end();it++)
                cout<<*it<<" ";
            cout<<endl;
        }while(next_dir(dir));
*/

    }

    return 0;
}
