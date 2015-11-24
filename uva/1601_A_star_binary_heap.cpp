#include <cstdio>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
using namespace std;
int w,h,n;
bool* graph=NULL;

struct pos{
    int r;
    int c;
    char ico;
    pos(int a,int b,char c)
    {
        r=a;
        c=b;
        ico=c;
    }

    pos operator+=(pos& a)
    {
        r+=a.r;
        c+=a.c;
        return *this;
    }

    pos operator+(pos& a)
    {
        return  pos(r+a.r,c+a.c,ico);
    }

    bool operator==(const pos& a) const
    {
        return  r == a.r && c == a.c && ico == a.ico;
    }

    int id()
    {
        return r * w + c ;
    }

    int dist(pos& a)
    {
        return abs(r-a.r)+abs(c-a.c);
    }
};

enum DIR{S,U,L,R,D};
pos d[5]=
{
    pos(0,0,0),
    pos(-1,0,0),
    pos(0,-1,0),
    pos(0,1,0),
    pos(1,0,0)
};

bool ico_cmp( pos a , pos b )
{
    return a.ico < b.ico ;
}



struct state{
    vector<pos> s;
    int id()
    {
        int val=0,base=w*h;
        for( int b = 0 ; b < n ; b++ )
        {
            val += ( s[b].id() );
            val *= base;
        }
        return val;
    }

    void push(pos a)
    {
        s.push_back(a);
        std::sort( s.begin() , s.end() , ico_cmp );
    }
    bool operator==(const state& a) const
    {
        return s==a.s;
    }
    pos& operator[](int i)
    {
        return s[i];
    }
};


struct Node{
    state cond;
    int f,g,h;
    Node(){}
    Node( int val_g , state cnd , state e )
    {
        cond=cnd;
        g=val_g;
        h=0;
        for(int i=0 ; i < n ; i++ )
        {
            h +=  cnd[i].dist( e[i] ) ;
        }
        f=g+h;
    }
    bool operator>(const Node& a) const
    {
        return f > a.f;
    }
    bool operator<(const Node& a) const
    {
        return f < a.f;
    }
    bool operator==(const Node& a) const
    {
        return f == a.f;
    }
    bool operator>=(const Node& a) const
    {
        return f >= a.f;
    }

};

struct binary_heap{
    vector<Node> arr;

    binary_heap()
    {
        arr.push_back( Node() );
    }
    int size()
    {
        return arr.size()-1;
    }


    void up(int i)
    {
        while( i>1 && i<=size()  )
        {
            if( arr[i] < arr[i/2] )
            {
                swap( arr[i] , arr[i/2] );
                i/=2;
            }
            else break;
        }
    }

    void down( int r )
    {
        while( r>=1 && r <= size() )
        {
            int MIN = r;
            for(int l=2*r ; l < size() && l <= (2*r+1) ; l++ )
            {
                if( arr[l] < arr[MIN] )
                {
                    MIN = l;
                }
            }
            if( MIN != r)
            {
                swap( arr[r] , arr[MIN] );
                r = MIN;
            }
            else break;
        }
    }

    void push(Node a)
    {
        arr.push_back(a);
        up(size());
    }

    Node pop()
    {
        Node t=arr[1];
        swap( arr[1] , arr.back() );
        arr.pop_back();

        down(1);

        return t;
    }

    Node top()
    {
        return arr[1];
    }
    bool empty()
    {
        return size() < 1;
    }
    vector<Node>::iterator search_state( state cnd )
    {
        for(vector<Node>::iterator it = arr.begin()+1 ; it != arr.end() ; it++ )
        {
            if( (*it).cond == cnd ) return it;
        }
        return arr.begin();
    }

    void replace( vector<Node>::iterator it , Node val )
    {
        *it=val;
        int i= it - arr.begin() ;
        up(i);
        down(i);
    }
};


bool get_graph( pos a )
{
    if( a.r < 0 || a.r >= h || a.c < 0 || a.c >= w )
        return false;
    else return *( graph + a.id() );
}

void set_graph( pos a , bool val )
{
    *( graph + a.id() ) = val;
}


bool next_dir( const state& pre , state cnd , vector<int>& dir , vector< vector< int > >& cand_dir )
{
    int cur=n-1;
    while( cur!=-1 )
    {
        if( dir[cur] == (cand_dir[cur].size()-1) )
        {
            dir[cur]=0;
            cur--;
        }
        else
        {
            dir[cur]++;

            for(int b = 0 ; b < n ; b++)
                cnd[b] = cnd[b] + d[ cand_dir[ b ][ dir[b] ] ];

            bool error=false;
            for( int first = 0 ; first < n-1 ; first++ )
            {
                for( int second = first + 1 ; second < n ; second++ )
                {
                    if(
                        ( cnd[ first ] == cnd[ second ] ) ||
                        ( pre.s[ first ] == cnd[ second ] && pre.s[ second ] == cnd[ first ] )
                      )
                    {
                        error = true ;
                        break ;
                    }
                }
                if(error)
                    break;
            }

            if(error)
            {
                cnd=pre;
                continue;
            }
            else return true;
        }
    }
    return false;
}



bool cmp_state( Node a , Node b )
{
    return a.cond.id() < b.cond.id() ;
}

int A_star( state& start , state& goal )
{
    binary_heap open;
    vector< Node > close;
    open.push( Node(0,start,goal) );
    while( !open.empty() )
    {
        Node cur=open.pop();
        if( cur.cond == goal )
            return cur.g;
        close.push_back(cur);
        sort( close.begin() , close.end() , cmp_state );

        vector<int> dir(n,0);
        state pre = cur.cond;
        state cnd = cur.cond;


        vector< vector< int > > cand_dir( n , vector<int>(1,0) );
        for(int b=0;b<n;b++)
            for(int cd = 1; cd <= 4 ; cd++ )
                if( get_graph( cnd[b]+d[cd] ) )
                    cand_dir[b].push_back(cd);

        if( next_dir( pre , cnd , dir ,cand_dir) )
        {
            do
            {
                Node nxt( cur.g+1 , cnd , goal );

                vector<Node>::iterator l_b = lower_bound( close.begin() , close.end() , nxt , cmp_state );
                if( nxt.cond == l_b->cond && nxt.g >= l_b->g )
                    continue;

                vector<Node>::iterator ext;
                if( ( ext = open.search_state( nxt.cond ) ) != open.arr.begin() )
                {
                    if( nxt.g < (*ext).g )
                    {
                        open.replace(ext,nxt);
                        for(int i=0;i<n;i++)
                            printf("%c:%d ",nxt.cond[i].ico,cand_dir[i][dir[i]]);
                        printf("\n");

                    }
                    continue;
                }
                for(int i=0;i<n;i++)
                    printf("%c:%d ",nxt.cond[i].ico,cand_dir[i][dir[i]]);
                printf("\n");


                open.push( nxt );
                cnd=pre;
            }while( next_dir( pre , cnd , dir ,cand_dir) );
        }
        else continue;
    }
}


int main()
{
    while( scanf("%d%d%d",&w,&h,&n) && w && h && n )
    {
        char ch;
        while( ( ch = getchar() ) != '\n' );

        graph = ( graph == NULL ) ? (bool*)malloc( sizeof(bool) * w * h )
                                  : (bool*)realloc( graph , sizeof(bool) * w * h );

        state start,goal;

        for(pos it(0,0,0); it.r < h ; it.r++)
        {
            for(it.c = 0 ; it.c < w ; it.c++)
            {
                if( ( ch = getchar() ) == '#' )
                {
                    set_graph(it , false);
                }
                else
                {
                    set_graph(it , true);

                    if( isalpha(ch) )
                    {
                        if( ch == toupper(ch) )
                        {
                            it.ico=toupper(ch);
                            goal.push( it );
                            it.ico=0;
                        }
                        else
                        {
                            it.ico=toupper(ch);
                            start.push( it );
                            it.ico=0;
                        }
                    }
                }
            }

            getchar();
        }

        printf("%d\n", A_star( start , goal ) );
    }

    free(graph);

    return 0;
}
