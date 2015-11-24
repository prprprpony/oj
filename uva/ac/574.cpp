#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
string int2str(int& i)
{
    string s;
    stringstream ss(s);
    ss<<i;
    return ss.str();
}

bool iddfs( int* x ,int n, int& t , string s )
{
    if( t == 0 )
    {
        cout << s << endl;
        return true;
    }


    bool res=false;
    if( s.size() )s.push_back('+');
    for( int i = upper_bound( x , x+n , t )-1-x ; i >= 0 ; i-- )
    {
        if( i < n-1 && x[i] == x[i+1] )continue;
        if( (i+1)*x[i] < t )break;
        string num = int2str( x[i] );
        s += num;
        t -= x[i];
        if( iddfs( x , i , t , s  ) && !res )
            res=true;
        t += x[i];
        s.erase( s.end()-num.size() , s.end() );
    }
    if( s.size() )s.erase( s.end()-1 );

    return res;
}

int main()
{
    int t,n;
    while( scanf("%d%d",&t,&n) != EOF && n )
    {
        int x[n];
        for(int i=n-1;i>=0;i--)
            scanf("%d",&x[i]);
        printf("Sums of %d:\n",t);
        string s;
        if( ! iddfs(x,n,t,s) )
            printf("NONE\n");
    }
    return 0;
}
