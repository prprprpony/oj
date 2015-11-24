#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void dfs(vector<string>& g,int level,int left,int right)
{
    cout<<'(';

    if( (level%3) == 0 )
    {
        for(int i=left ; i<=right && i<=(g[level].length()-1); i++)
        {
            if(g[level][i]!=' ')
            {
                cout<< g[level][i] ;

                int l=i,r=i,lvl=level+2;

                if( (level+3) < g.size() )
                    if( g[level+1][i] == '|' )
                    {
                        while( g[lvl][l-1] == '_' && l > 0 )l--;
                        while( g[lvl][r+1] == '_' && r < (g[lvl].length()-1) )r++;

                        lvl++;
                    }

                dfs(g,lvl,l,r);
            }
        }
    }

    cout<<')';
    return;
}

int main()
{
    int n;
    string buf;
    getline(cin,buf) ;
    stringstream ss(buf);
    ss>>n;

    while(n--)
    {
        vector<string> g;

        while( getline(cin,buf) && buf[0] != '#' )
            g.push_back(buf);

        dfs( g , 0 , 0 , g[0].length()-1 );
        cout<<endl;
    }

    return 0;
}
